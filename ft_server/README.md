# ft_server

ft_server 는시스템 관리에 대한 과제로, 서버를 운영하는 것을 자동화 하는 방법을 아는 과제임.

# Docker

- [Docker Document (get-started)](https://docs.docker.com/get-started/)

### Container

- host 내의 다른 프로세스로 부터 분리된 프로세스.
- Container Image
    - container의 filesystem을 지원
    - application 을 실행시키는데 필요한 모든 것을 포함함 (ex. all dependencies, configuration, scripts, binaries, etc.)
    - environment variables, a default command to run, and other metadata 도 포함함
    - 

### Docker Command

- Tutorial
    - build 가 필요한 레포를 복사하고, container 로 실행

    ```jsx
    docker run --name repo alpine/git \https://github.com/docker/getting-started.git docker cp repo:/git/getting-started/ .
    ```

    - build image ( build 할 디렉토리 내에서 실행)

    ```jsx
    docker build -t docker101tutorial .
    ```

    - Start Container ( 빌드한 이미지로 컨테이너 시작 )

    ```jsx
    docker run -d -p 80:80 \ --name docker-tutorial docker101tutorial 
    ```

    - Save and share your image on Docker Hub to enable other users to easily download and run the image on any destination machine.

    ```jsx
    docker tag docker101tutorial sunhpark/docker101tutorial
    docker push sunhpark/docker101tutorial
    ```

    - To push a new tag to this repository,

    ```jsx
    docker push sunhpark/docker101tutorial:tagname
    ```

    - 접속 하는 방법

    ```jsx
    http://localhost/tutorial/
    ```

- `docker run` flag
    - `-d` : detached mode 로 container 를 실행
    - `-p {#host-port}:{#container-port}` : map port number
    - `--name {name}`  :
    - single character flag는 같이 사용 될 수 있음 (ex. `-dp` )
