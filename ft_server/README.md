# ft_server 🖥

ft_server 는시스템 관리에 대한 과제로, 서버를 운영하는 것을 자동화 하는 방법을 아는 과제임.

# Docker

- [Docker Document (get-started)](https://docs.docker.com/get-started/)

### Container

- host 내의 다른 프로세스로 부터 분리된 프로세스.
- Container Image
    - container의 filesystem을 지원
    - application 을 실행시키는데 필요한 모든 것을 포함함 (ex. all dependencies, configuration, scripts, binaries, etc.)
    - environment variables, a default command to run, and other metadata 도 포함함

### Docker Command

- Tutorial
- `docker run` flag
- `docker build` flag

### Application 올리기

- application source code 를 필요로 함(local or repo)
- App folder 내에 package.json, ./src, ./spec

### Container Image Compile

1. `Dockerfile` 을 생성 (package.json 과 같은 폴더 안에 있어야 함)

    ```jsx
    // Dockerfile
    FROM node:12-apline
    WORKDIR /app
    COPY . .
    RUN yarn install --production
    CMD ["node", "src/index.js"]
    ```

2. `Dockerfile`이 있는 폴더에서 `docker build` 를 이용해서 containger image 를 build 함.

    ```jsx
    docker build -t getting-started 
    ```

    - 이때 에러가 나는데, 에러메세지는 다음과 같다.
    - `Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?`
    - docker daemon에 연결할 수 없다. 라는 에러.
    - docker daemon ? Docker API request를 받고, Docker objects(images, containers, networks, and volumes) 를 관리함. Docker service를 관리하는 다른 daemon들과 함께 소통 가능.
    - 정말 단순히 도커를 켜주지 않아서 생기는 에러
    - 실행 완료된 모습

    ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6348b8c6-0ec4-4d29-adfc-29ed4f40ca91/_2021-01-02__7.11.24.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6348b8c6-0ec4-4d29-adfc-29ed4f40ca91/_2021-01-02__7.11.24.png)

3. App Container 시작하기
    - `docker run` 명령어 이용

    ```jsx
    docker run -dp 3000:3000 getting-started
    ```

    - 하면 이렇게 나오는데 무슨 키지..?

        ![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d6a18164-034a-4303-b16b-82c5c1599145/_2021-01-02__7.14.31.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d6a18164-034a-4303-b16b-82c5c1599145/_2021-01-02__7.14.31.png)

### Update app

- 이미지를 생성하고, 빌드하는 과정을 똑같이 거치면 id 에러가 발생한다. 그래서 컨테이너의 아이디를 받아서 swap 해 줄 필요가 있음.
1. `docker ps` : container의 id 를 받아온다.
2. `docker stop <the-container-id>` : id를 이용해 실행을 중지
3. `docker rm <the-container-id>` : container 삭제
    - `-f` tag : 강제성 부여.
4. 이후 `docker run` 을 재실행.

## Dockerfile 작성법

```jsx
FROM ubuntu:18.04
COPY . /app
RUN make /app
CMD python /app/app.py
EXPOSE 80
LABEL com.example.version="0.0.1-beta" com.example.release-date="2015-02-12"
VOLUME /myvol // VOLUME ["/data"]
ENV PG_MAJOR=9.3
ENV PG_VERSION=9.3.4
RUN curl -SL https://example.com/postgres-$PG_VERSION.tar.xz | tar -xJC /usr/src/postgress && …
ENV PATH=/usr/local/postgres-$PG_MAJOR/bin:$PATH

ENV DIRPATH=/path
WORKDIR $DIRPATH/$DIRNAME
RUN pwd
```

- `FROM` : 해당 docker image 에 대한 레이어를 만들어 줌
- `COPY/ADD` : 현재 docker client의 디렉토리의 파일들을 container에 추가 / copy가 더 선호 됨 / add는 tar 형식의 파일을 자동으로 추출하는데 이용 / 여러개의 도커파일을 이용할 경우 모든 곳에 넣어주어야 함.
- `RUN` : app build. (make, yarn, npm etc.)
- `CMD ["executable", "param1", "param2"…]` : 어떤 것을 실행할 것인지를 구체적으로 작성함.
- `\` : 개행
- `LABEL` : 프로젝트에 따라 Image를 조직할 수 있음. string의 경우 space가 포함되면 ""로 반드시 감싸 주어야 함.
    - ex
- `EXPOSE` : container가 연결 될 포트# / docker run 명령어로도 지정해 줄 수 있음.
- `ENV` : `PATH` 의 환경 변수를 업데이트 / container화 하려는 서비스에 특정한 필수 환경변수를 제공 하는데 유용 / 일반적으로 사용되는 버전을 세팅하는데 이용 가능.
- `ENTRYPOINT` : image의 main command를 설정, `CMD` 의 기본 플래그로 사용됨. / shell script와 함께 이용 가능.
    - ex.
- `VOLUME` : mount point를 설정해줌, JSON 배열로도 설정이 가능함. / docker container에서 사용 된 database stroge area, configuration storage, or files/folders을 보여주는데 사용되어야 한다.  / 이미지가 변경가능하거나, 사용자에게 서비스 되는 파트면 적용해 주는 것이 좋음.
- `USER <user>[:<group>]` : username을 지정해줌, 서비스가 권한이 없이 돌아 갈 수 있으면, user를 non-root user로 변경
- `WORKDIR` : working directory를 설정, 다른 커맨드들이 동작하는 위치. 만약 해당 디렉토리가 존재하지 않으면 생성됨. / 여러줄로 선언될 수 있음 - 의존 관계를 나타냄
- `ARG <name>[=<default value>]` : docker build를 할 때 변수를 설정해 줄 수 있음. / 미리정의된 ARG도 있음 (predeined ARGs) - HTTP_PROXY, FTP_PROXY, NO_PROXY

# Ngix

- HTTP and reverse proxy server
- generic TCP/UDP proxy server
- 그냥 웹서버임
- 참고 : [https://kscory.com/dev/nginx/install](https://kscory.com/dev/nginx/install)
- `brew install nginx`

# SSL(Secure Sockets Layer) protocol

- 참고자료
    - [What is SSL? by Cloudflare](https://www.cloudflare.com/ko-kr/learning/ssl/what-is-ssl/)

- autoindex

# Mandatory

1. You must set up a web server with Nginx, in only one docker container. The container OS must be debian buster
    - docker web server 설정하기
2. dd
