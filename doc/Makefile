all: images/lars.pdf

images/lars.pdf: ../examples/lars.msc ../src/Progtalk
	../src/Progtalk < $<
	latex communication
	dvipdf communication
	mv communication.pdf $@

