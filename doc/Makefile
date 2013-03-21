all: images/lars.pdf images/test1.pdf progtalk.pdf 

# images/%.pdf: ../examples/%.msc ../src/Progtalk
# 	../src/Progtalk < $<
# 	latex communication
# 	dvipdf communication
# 	mv communication.pdf $@

images/%.pdf: ../examples/%.msc ../src/Progtalk
	../src/Progtalk < $<
	pdflatex -shell-escape communication
	mv communication.pdf $@

progtalk.pdf: agradecimientos.tex conclusiones.tex disegno.tex intromsc.tex portada.tex resumen.tex dedicatoria.tex indices.tex lenguaje.tex progtalk.tex summary.tex
	pdflatex -shell-escape progtalk
	bibtex progtalk
	pdflatex -shell-escape progtalk
	pdflatex -shell-escape progtalk

