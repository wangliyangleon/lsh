.PHONY:all
all:rand_people_maker 
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:clean
clean:
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf rand_people_maker
	rm -rf ./output/bin/rand_people_maker
	rm -rf src/rand_people_maker_rand_people_maker.o

rand_people_maker:src/rand_people_maker_rand_people_maker.o \
  ../libsp.a
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40mrand_people_maker[0m']"
	g++ src/rand_people_maker_rand_people_maker.o  ../libsp.a ../thirdparty/Gtest/lib/libgtest.a \
  ../thirdparty/gflags/lib/libgflags.a -lpthread \
  -lcrypto \
  -lm \
  -lssl  -o rand_people_maker
	mkdir -p ./output/bin
	cp -f rand_people_maker ./output/bin

src/rand_people_maker_rand_people_maker.o:src/rand_people_maker.cpp \
  src/rand_people_maker.cpp
	@echo "[[1;32;40mBUILD[0m][Target:'[1;32;40msrc/rand_people_maker_rand_people_maker.o[0m']"
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
  -Wall  -o src/rand_people_maker_rand_people_maker.o src/rand_people_maker.cpp
