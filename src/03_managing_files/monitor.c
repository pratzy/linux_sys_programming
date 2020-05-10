/*
    Monitor specified files for change, using inotify system call
*/
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h> //inotify calls are not available on mac, use fswatch instead
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

#define BUFSIZE (100 * (sizeof(struct inotify_event) + NAME_MAX + 1))

int main()
{
    FILE *fconfig, *fout;
    char watchname[PATH_MAX];
    struct stat sb;
    int notifyfd, watchfd;
    char eventbuf[BUFSIZE];
    int n;
    struct inotify_event *event;

    /* Hold the names of files to be watched, indexed by the watch descriptor */
    char watchednames[100][NAME_MAX + 1];

    notifyfd = inotify_init();

    /* Open the config file containing list of files only (no directories)*/
    if ((fconfig = fopen("monitor.conf", "r")) == NULL)
    {
        fprintf(stderr, "Unable to find config file monitor.conf. Exiting...\n");
        exit(1);
    }

    /* Read all file names from config file*/
    while (fgets(watchname, PATH_MAX, fconfig) != NULL)
    {
        // Remove newline
        watchname[strlen(watchname) - 1] = '\0';
        if (stat(watchname, &sb) < 0)
        {
            fprintf(stderr, "Cannot stat %s, ignored\n", watchname);
            continue;
        }

        if (S_ISREG(sb.st_mode))
        {
            /* Add this regular file to watch list */
            if ((watchfd = inotify_add_watch(notifyfd, watchname,
                                             IN_MODIFY | IN_DELETE_SELF)) < 0)
            {
                fprintf(stderr, "Error adding watch for %s", watchname);
            }
            else
            {
                fprintf(stdout, "Watching %s on descriptor %d ...", watchname, watchfd);
                strcpy(watchednames[watchfd], watchname);
            }
        }
        else
        {
            // Maybe a directory, skip it
            fprintf(stderr, "%s is not a regular file, ignored\n", watchname);
        }
    }

    /* All the watches are now added, now report events*/
    fout = fopen("monitor.out", "a");

    while (1)
    {
        n = read(notifyfd, eventbuf, BUFSIZE);

        // Loop over all the events and report them.
        // Events may not be of same length
        for (char *p = eventbuf; p < eventbuf + n;)
        {
            event = (struct inotify_event *)p;
            p += sizeof(struct inotify_event) + event->len;

            // Display the event
            if (event->mask & IN_MODIFY)
                fprintf(fout, "%s was modified\n", watchednames[event->wd]);
            if (event->mask & IN_DELETE_SELF)
                fprintf(fout, "%s was deleted\n", watchednames[event->wd]);

            fflush(fout);
        }
    }

    return EXIT_SUCCESS;
}