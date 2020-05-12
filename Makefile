docker-build:
	docker build -t ubuntu-vs .
	docker run -d -p 12345:22 -p 55555:55555 --security-opt seccomp:unconfined --name ubuntu-vs -it ubuntu-vs /bin/bash

docker-connect:
	docker exec -it ubuntu-vs /bin/bash

docker-run2:
	docker commit --message="Snapshot of ubuntu-vs" ubuntu-vs ubuntu-vs:clone
	docker run -d -p 12346:22 -p 55556:55555 --security-opt seccomp:unconfined --name ubuntu-vs2 -it ubuntu-vs:clone /bin/bash
