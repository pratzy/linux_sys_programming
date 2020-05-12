docker-build:
	docker build -t ubuntu-vs .
docker-run: docker-build
	docker run -p 5000:22 -it --hostname ubunut-vs ubuntu-vs /bin/bash
