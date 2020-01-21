PROJECT_NAME=fcgisrv
PROJECT_DESCRIPTION=

ROOT_DIR=$(shell pwd)
BUILD_PREFIX?=build
BUILD_SYSTEM?=Ninja
BUILD_TYPE?=Debug

BUILD_DIR=${BUILD_PREFIX}/${BUILD_TYPE}

help:
	@echo "${PROJECT_NAME}"
	@echo ""
	@echo "Available targets:"
	@echo "------------------"
	@echo "  debug:            Builds the project in debug mode"
	@echo "  release:          Builds the project for release"
	@echo "  clean:            Wipes the build directories"

debug:
	@${MAKE} --no-print-directory BUILD_SYSTEM='${BUILD_SYSTEM}' BUILD_TYPE=Debug _build

release:
	@${MAKE} --no-print-directory BUILD_SYSTEM='${BUILD_SYSTEM}' BUILD_TYPE=Release _build

clean:
	$(RM) -rf ${BUILD_PREFIX}

_build: ${BUILD_DIR}/CMakeFiles
	cmake --build ${BUILD_DIR}

${BUILD_DIR}:
	mkdir -p $@

${BUILD_DIR}/CMakeFiles: ${BUILD_DIR}
	@echo "Setting up build system using '${BUILD_SYSTEM}'..."
	@cd ${BUILD_DIR} && cmake \
		-DPROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}" \
		-DPROJECT_NAME="${PROJECT_NAME}" \
		-DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
		-G"${BUILD_SYSTEM}" ${ROOT_DIR}
