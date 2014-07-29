.PHONY:all
all:test_timer test_util test_people test_people_manager test_lsh
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:clean
clean:
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf test_timer
	rm -rf ./output/bin/test_timer
	rm -rf test_util
	rm -rf ./output/bin/test_util
	rm -rf test_people
	rm -rf ./output/bin/test_people
	rm -rf test_people_manager
	rm -rf ./output/bin/test_people_manager
	rm -rf test_lsh
	rm -rf ./output/bin/test_lsh
	rm -rf src/test_timer_test_timer.o
	rm -rf src/test_util_test_util.o
	rm -rf src/test_people_test_people.o
	rm -rf src/test_people_manager_test_people_manager.o
	rm -rf src/test_lsh_test_lsh.o

test_timer:src/test_timer_test_timer.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest_timer[0m']"
	g++ src/test_timer_test_timer.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o test_timer
	mkdir -p ./output/bin
	cp -f test_timer ./output/bin

test_util:src/test_util_test_util.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest_util[0m']"
	g++ src/test_util_test_util.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o test_util
	mkdir -p ./output/bin
	cp -f test_util ./output/bin

test_people:src/test_people_test_people.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest_people[0m']"
	g++ src/test_people_test_people.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o test_people
	mkdir -p ./output/bin
	cp -f test_people ./output/bin

test_people_manager:src/test_people_manager_test_people_manager.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest_people[0m']"
	g++ src/test_people_manager_test_people_manager.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o test_people_manager
	mkdir -p ./output/bin
	cp -f test_people_manager ./output/bin

test_lsh:src/test_lsh_test_lsh.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mtest_people[0m']"
	g++ src/test_lsh_test_lsh.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o test_lsh
	mkdir -p ./output/bin
	cp -f test_lsh ./output/bin

src/test_timer_test_timer.o:src/test_timer.cpp \
  src/test_timer.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/test_timer_test_timer.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include \
  -I../ \
  -I../include \
  -I../output \
  -I../output/include -I../thirdparty/Gtest \
  -I../thirdparty/Gtest/include \
  -I../thirdparty/Gtest/output \
  -I../thirdparty/Gtest/output/include \
  -I../thirdparty/gflags \
  -I../thirdparty/gflags/include \
  -I../thirdparty/gflags/output \
  -I../thirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall  -o src/test_timer_test_timer.o src/test_timer.cpp

src/test_util_test_util.o:src/test_util.cpp \
  src/test_util.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/test_util_test_util.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include \
  -I../ \
  -I../include \
  -I../output \
  -I../output/include -I../thirdparty/Gtest \
  -I../thirdparty/Gtest/include \
  -I../thirdparty/Gtest/output \
  -I../thirdparty/Gtest/output/include \
  -I../thirdparty/gflags \
  -I../thirdparty/gflags/include \
  -I../thirdparty/gflags/output \
  -I../thirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall  -o src/test_util_test_util.o src/test_util.cpp

src/test_people_test_people.o:src/test_people.cpp \
  src/test_people.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/test_people_test_people.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include \
  -I../ \
  -I../include \
  -I../output \
  -I../output/include -I../thirdparty/Gtest \
  -I../thirdparty/Gtest/include \
  -I../thirdparty/Gtest/output \
  -I../thirdparty/Gtest/output/include \
  -I../thirdparty/gflags \
  -I../thirdparty/gflags/include \
  -I../thirdparty/gflags/output \
  -I../thirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall  -o src/test_people_test_people.o src/test_people.cpp

src/test_people_manager_test_people_manager.o:src/test_people_manager.cpp \
  src/test_people_manager.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/test_people_manager_test_people_manager.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include \
  -I../ \
  -I../include \
  -I../output \
  -I../output/include -I../thirdparty/Gtest \
  -I../thirdparty/Gtest/include \
  -I../thirdparty/Gtest/output \
  -I../thirdparty/Gtest/output/include \
  -I../thirdparty/gflags \
  -I../thirdparty/gflags/include \
  -I../thirdparty/gflags/output \
  -I../thirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall  -o src/test_people_manager_test_people_manager.o src/test_people_manager.cpp

src/test_lsh_test_lsh.o:src/test_lsh.cpp \
  src/test_lsh.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/test_lsh_test_lsh.o[0m']"
	g++ -c -I. \
  -I./include \
  -I./output \
  -I./output/include \
  -I../ \
  -I../include \
  -I../output \
  -I../output/include -I../thirdparty/Gtest \
  -I../thirdparty/Gtest/include \
  -I../thirdparty/Gtest/output \
  -I../thirdparty/Gtest/output/include \
  -I../thirdparty/gflags \
  -I../thirdparty/gflags/include \
  -I../thirdparty/gflags/output \
  -I../thirdparty/gflags/output/include  -g \
  -pipe \
  -std=c++11 \
  -W \
  -Wall  -o src/test_lsh_test_lsh.o src/test_lsh.cpp
