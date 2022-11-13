
include(CheckCSourceRuns)
include(CheckCXXSourceRuns)

check_c_source_runs("
  #include <arpa/inet.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_ARPA_INET_H)

check_c_source_runs("
  #include <dlfcn.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_DLFCN_H)

check_c_source_runs("
  #include <stdio.h>
  int main(int argc, char *argv[]) {
    int a = fileno(stdin);
    return 0;
  }
" HAVE_FILENO_PROTO)

check_c_source_runs("
  #include <stdio.h>
  int main(int argc, char *argv[]) {
    fpos_t a;
    return 0;
  }
" HAVE_FPOS)

check_c_source_runs("
  #include <inttypes.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_INTTYPES_H)

check_c_source_runs("
  #include <limits.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_LIMITS_H)

check_c_source_runs("
  #include <memory.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_MEMORY_H)

check_c_source_runs("
  #include <netdb.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_NETDB_H)

check_c_source_runs("
  #include <netinet/in.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_NETINET_IN_H)

check_c_source_runs("
  #include <stdint.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_STDINT_H)

check_c_source_runs("
  #include <stdlib.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_STDLIB_H)

check_c_source_runs("
  #include <strings.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_STRINGS_H)

check_c_source_runs("
  #include <string.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_STRING_H)

check_c_source_runs("
  #include <sys/param.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_SYS_PARAM_H)

check_c_source_runs("
  #include <sys/socket.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_SYS_SOCKET_H)

check_c_source_runs("
  #include <sys/stat.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_SYS_STAT_H)

check_c_source_runs("
  #include <sys/time.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_SYS_TIME_H)

check_c_source_runs("
  #include <sys/types.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_SYS_TYPES_H)

check_c_source_runs("
  #include <unistd.h>
  int main(int argc, char *argv[]) {
    return 0;
  }
" HAVE_UNISTD_H)

check_c_source_runs("
  #include <sys/types.h>
  int main(int argc, char *argv[]) {
    ssize_t a;
    return 0;
  }
" HAVE_SSIZE_T)

check_cxx_source_runs("
#include <streambuf>
int main() {
	std::streambuf::char_type a;
	return 0;
}
" HAVE_STREAMBUF_CHAR_TYPE)

FIND_PACKAGE(Threads)

if(CMAKE_USE_PTHREADS_INIT)
  set(HAVE_PTHREAD 1)
endif(CMAKE_USE_PTHREADS_INIT)