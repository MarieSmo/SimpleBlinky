PACK?=SimpleBlinky
SYS?=SYS()

V?=0.0.2
TOOLS=./tools
BIP=${TOOLS}/bipc/bin/bipc.sh
DR_PATH=${TOOLS}/drbip
BIPEXEC?=./exec.sh
VER?=


.PHONY: default setup execute genbip gendrbip clean all info gencode compile

default : info

gencode:
	make clean
	make setup
	make genbip
	@echo "--------"
	@echo "BIP generated"
	@echo "--------"
	make gendrbip
	@echo "--------"
	@echo "DR-BIP generated"
	@echo "--------"
	@echo "--------"
	@echo "Code generated, use 'compile' to continue"
	@echo "--------"

setup:
	make clean
	mkdir -p output build

cleanmodel:
	rm -rf model/*.bip model/*.drbip model/*.cpp

genbip:
	${BIP} -p ${PACK} -d "${SYS}" \
			-f 'ujf.verimag.bip.middleend.gluetranslator.GluetranslatorFilter!ujf.verimag.bip.middleend.xflattening.XflatteningFilter' \
			-I model \
		  --gencpp-output-dir output --gencpp-no-engine

gendrbip:
	${DR_PATH}/drbip model${PRE}/${PACK}${VER}.drbip output/Deploy model${PRE}
	${DR_PATH}/scripts/mktemplates ${PACK} output/Deploy
	cp -f model/*.cpp output/Deploy 2>/dev/null || true
	cp -f model/*.h output/Deploy  2>/dev/null || true
	cp -f model/*.hpp output/Deploy 2>/dev/null || true

compile:
	cd build && cmake -DBIPFLAGS="$2 " ../output
	cd build && make
	@echo "--------"
	@echo "Code generated, use 'execute' to run the program"
	@echo "--------"

execute:
	./build/system

clean:
	rm -rf build output *.json

info:
	$(info "Read README to execute models")
