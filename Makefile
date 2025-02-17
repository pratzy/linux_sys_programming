docker-build:
	docker build -t ubuntu-vs .
	# docker run -d -p 12345:22 -p 55555:55555 --security-opt seccomp:unconfined --name ubuntu-vs -it ubuntu-vs /bin/bash

docker-run-1:
	docker run -v ${PWD}:/root/home -d -p 12345:22 -p 55555:55555 --security-opt seccomp:unconfined --name ubuntu-vs-1 -it ubuntu-vs /bin/bash

docker-run-2:
	docker run -v ${PWD}:/root/home -d -p 12346:22 -p 55556:55555 --security-opt seccomp:unconfined --name ubuntu-vs-2 -it ubuntu-vs /bin/bash

docker-stop-1:
	docker container stop ubuntu-vs-1

docker-rm-1: docker-stop-1
	docker container rm ubuntu-vs-1

docker-stop-2:
	docker container stop ubuntu-vs-2

docker-rm-2: docker-stop-2
	docker container rm ubuntu-vs-2

docker-connect:
	docker exec -it ubuntu-vs /bin/bash

docker-commit: #Do after initializing the git repo and generating ssh keys
	docker <find image id> commit ubuntu-vs:init

docker-create-vms:
	docker-compose up -d

docker-commit:
	docker commit --message="Snapshot of ubuntu-vs" ubuntu-vs ubuntu-vs:init
