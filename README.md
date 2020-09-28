# Build

```
mkdir build
cd build && cmake ..
make Counter
```

# Usage

```
cat <filename> | ./Counter/Counter
```
or
```
./Counter/Counter <filename>
```
# Docker usage
build docker image:

```
docker build -t counter .
```
Run counter in docker image:

```
cat data/data.txt | docker run -i counter
```

# TODO
stylecheck
RPM
