#########################################################################################
##  Stage 2: build DALI wheels on top of the dependencies image built in Stage 1
#########################################################################################
ARG DEPS_IMAGE_NAME=nvcr.io/nvidia/pytorch:19.05-py3
# clean builder without source code inside
FROM ${DEPS_IMAGE_NAME} as builder

ARG PYVER=2.7
ARG PYV=27

ENV PYVER=${PYVER} PYV=${PYV} PYTHONPATH=/usr/bin/python2.7

ENV PYBIN=${PYTHONPATH}/bin \
    PYLIB=${PYTHONPATH}/lib

ENV PATH=${PYBIN}:${PATH} \
    LD_LIBRARY_PATH=/usr/local/cuda/lib64/stubs:/opt/dali/${DALI_BUILD_DIR}:${PYLIB}:${LD_LIBRARY_PATH} \
    LIBRARY_PATH=/usr/local/cuda/lib64/stubs:/opt/dali/${DALI_BUILD_DIR}:${PYLIB}:${LIBRARY_PATH}

#RUN yum -y install python27
RUN apt-get -y install python2.7

RUN pip install future setuptools wheel && \
    rm -rf /root/.cache/pip/

RUN ln -s /usr/local/cuda/lib64/stubs/libcuda.so /usr/local/cuda/lib64/stubs/libcuda.so.1 && \
    ldconfig

#COPY /home/yckim/dali_checkfreq/dali ./opt/dali

WORKDIR /opt/dali


ARG CC
ARG CXX
ENV CC=${CC}
ENV CXX=${CXX}
# Optional build arguments

ARG ARCH
ENV ARCH=${ARCH}
ARG CUDA_TARGET_ARCHS
ENV CUDA_TARGET_ARCHS=${CUDA_TARGET_ARCHS}
ARG CMAKE_BUILD_TYPE
ENV CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
ARG BUILD_TEST
ENV BUILD_TEST=${BUILD_TEST}
ARG BUILD_BENCHMARK
ENV BUILD_BENCHMARK=${BUILD_BENCHMARK}
ARG BUILD_NVTX
ENV BUILD_NVTX=${BUILD_NVTX}
ARG BUILD_PYTHON
ENV BUILD_PYTHON=${BUILD_PYTHON}
ARG BUILD_LMDB
ENV BUILD_LMDB=${BUILD_LMDB}
ARG BUILD_JPEG_TURBO
ENV BUILD_JPEG_TURBO=${BUILD_JPEG_TURBO}
ARG BUILD_NVJPEG
ENV BUILD_NVJPEG=${BUILD_NVJPEG}
ARG BUILD_LIBTIFF
ENV BUILD_LIBTIFF=${BUILD_LIBTIFF}
ARG BUILD_NVOF
ENV BUILD_NVOF=${BUILD_NVOF}
ARG BUILD_NVDEC
ENV BUILD_NVDEC=${BUILD_NVDEC}
ARG BUILD_LIBSND
ENV BUILD_LIBSND=${BUILD_LIBSND}
ARG BUILD_NVML
ENV BUILD_NVML=${BUILD_NVML}
ARG BUILD_FFTS
ENV BUILD_FFTS=${BUILD_FFTS}
ARG VERBOSE_LOGS
ENV VERBOSE_LOGS=${VERBOSE_LOGS}
ARG NVIDIA_DALI_BUILD_FLAVOR
ENV NVIDIA_DALI_BUILD_FLAVOR=${NVIDIA_DALI_BUILD_FLAVOR}
ARG GIT_SHA
ENV GIT_SHA=${GIT_SHA}
ARG DALI_TIMESTAMP
ENV DALI_TIMESTAMP=${DALI_TIMESTAMP}
ARG WHL_PLATFORM_NAME
ENV WHL_PLATFORM_NAME=${WHL_PLATFORM_NAME}

ARG NVIDIA_BUILD_ID
ENV NVIDIA_BUILD_ID ${NVIDIA_BUILD_ID:-0}
RUN mkdir /wheelhouse && chmod 0777 /wheelhouse

FROM builder
COPY . .
COPY build_helper.sh /opt/dali/docker/build_helper.sh

ARG DALI_BUILD_DIR=build-docker-release
WORKDIR /opt/dali/${DALI_BUILD_DIR}

RUN bash /opt/dali/docker/build_helper.sh
