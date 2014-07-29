.PHONY:all
all:simpeople libsp.a test tools 
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:clean
clean:
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf simpeople
	rm -rf ./output/bin/simpeople
	rm -rf libsp.a
	rm -rf ./output/lib/libsp.a
	$(MAKE) -C test clean
	$(MAKE) -C tools clean
	rm -rf src/simpeople_sp_people.o
	rm -rf src/simpeople_sp_util.o
	rm -rf src/simpeople_main.o
	rm -rf src/simpeople_sp_people_manager.o
	rm -rf src/simpeople_sp_def.o
	rm -rf src/simpeople_sp_lsh.o
	rm -rf src/sp_sp_people.o
	rm -rf src/sp_sp_util.o
	rm -rf src/sp_sp_people_manager.o
	rm -rf src/sp_sp_def.o
	rm -rf src/sp_sp_lsh.o

simpeople:src/simpeople_sp_people.o \
  src/simpeople_sp_util.o \
  src/simpeople_main.o \
  src/simpeople_sp_people_manager.o \
  src/simpeople_sp_def.o \
  src/simpeople_sp_lsh.o
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msimpeople[0m']"
	g++ src/simpeople_sp_people.o \
  src/simpeople_sp_util.o \
  src/simpeople_main.o \
  src/simpeople_sp_people_manager.o \
  src/simpeople_sp_def.o \
  src/simpeople_sp_lsh.o   thirdparty/Gtest/lib/libgtest.a \
  thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -o simpeople
	mkdir -p ./output/bin
	cp -f simpeople ./output/bin

libsp.a:src/sp_sp_people.o \
  src/sp_sp_util.o \
  src/sp_sp_people_manager.o \
  src/sp_sp_def.o \
  src/sp_sp_lsh.o
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mlibsp.a[0m']"
	ar crs libsp.a src/sp_sp_people.o \
  src/sp_sp_util.o \
  src/sp_sp_people_manager.o \
  src/sp_sp_def.o \
  src/sp_sp_lsh.o
	mkdir -p ./output/lib
	cp -f libsp.a ./output/lib

.PHONY:test
test:libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest[0m']"
	@echo "[[1;32;40mBUILD[0m][Entering directory:'[1;32;40mtest[0m']"
	$(MAKE) -C test
	@echo "[[1;32;40mBUILD[0m][Leaving directory:'[1;32;40mtest[0m']"

.PHONY:tools
tools:libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtools[0m']"
	@echo "[[1;32;40mBUILD[0m][Entering directory:'[1;32;40mtools[0m']"
	$(MAKE) -C tools
	@echo "[[1;32;40mBUILD[0m][Leaving directory:'[1;32;40mtools[0m']"

src/simpeople_sp_people.o:src/sp_people.cpp \
  src/sp_people.cpp \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h \
  include/sp_util.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_sp_people.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_sp_people.o src/sp_people.cpp

src/simpeople_sp_util.o:src/sp_util.cpp \
  src/sp_util.cpp \
  include/sp_util.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_sp_util.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_sp_util.o src/sp_util.cpp

src/simpeople_main.o:src/main.cpp \
  src/main.cpp \
  include/sp_lsh.h \
  include/sp_people_manager.h \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h \
  include/sp_timer.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_main.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_main.o src/main.cpp

src/simpeople_sp_people_manager.o:src/sp_people_manager.cpp \
  src/sp_people_manager.cpp \
  include/sp_people_manager.h \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_sp_people_manager.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_sp_people_manager.o src/sp_people_manager.cpp

src/simpeople_sp_def.o:src/sp_def.cpp \
  src/sp_def.cpp \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_sp_def.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_sp_def.o src/sp_def.cpp

src/simpeople_sp_lsh.o:src/sp_lsh.cpp \
  src/sp_lsh.cpp \
  include/sp_lsh.h \
  include/sp_people_manager.h \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/simpeople_sp_lsh.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2 \
  -DSCM_VERSION=\"undefined\"  -o src/simpeople_sp_lsh.o src/sp_lsh.cpp

src/sp_sp_people.o:src/sp_people.cpp \
  src/sp_people.cpp \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h \
  include/sp_util.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/sp_sp_people.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2  -o src/sp_sp_people.o src/sp_people.cpp

src/sp_sp_util.o:src/sp_util.cpp \
  src/sp_util.cpp \
  include/sp_util.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/sp_sp_util.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2  -o src/sp_sp_util.o src/sp_util.cpp

src/sp_sp_people_manager.o:src/sp_people_manager.cpp \
  src/sp_people_manager.cpp \
  include/sp_people_manager.h \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/sp_sp_people_manager.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2  -o src/sp_sp_people_manager.o src/sp_people_manager.cpp

src/sp_sp_def.o:src/sp_def.cpp \
  src/sp_def.cpp \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/sp_sp_def.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2  -o src/sp_sp_def.o src/sp_def.cpp

src/sp_sp_lsh.o:src/sp_lsh.cpp \
  src/sp_lsh.cpp \
  include/sp_lsh.h \
  include/sp_people_manager.h \
  include/sp_people.h \
  include/sp_def.h \
  thirdparty/gflags/include/gflags/gflags.h \
  thirdparty/gflags/include/gflags/gflags_declare.h
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/sp_sp_lsh.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include -Ithirdparty/Gtest \
  -Ithirdparty/Gtest/include \
  -Ithirdparty/Gtest/output \
  -Ithirdparty/Gtest/output/include \
  -Ithirdparty/gflags \
  -Ithirdparty/gflags/include \
  -Ithirdparty/gflags/output \
  -Ithirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall \
  -O2  -o src/sp_sp_lsh.o src/sp_lsh.cpp

