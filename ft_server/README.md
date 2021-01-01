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
- `docker run` flag
- `docker build` flag
    - `-t`  : our image의 flag tag, 해당 image 에 이름을 지어주는 과정.
    - `.` : 현재 폴더에 있는 Dockerfile을 이용하라는 명령

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
