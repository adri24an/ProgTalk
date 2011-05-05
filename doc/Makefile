all: images/lars.pdf images/test1.pdf

images/%.pdf: ../examples/%.msc ../src/Progtalk
	../src/Progtalk < $<
	latex communication
	dvipdf communication
	mv communication.pdf $@

