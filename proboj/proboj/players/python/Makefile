PROGRAM := player

PYSOURCES := $(wildcard *.py) $(wildcard libs/*.py) 

all: $(PROGRAM) $(PROGRAM).tar.gz

$(PROGRAM).tar.gz: $(PYSOURCES) Makefile
	@echo -e $(Green)"Making tar for submit..."$(Color_Off)
	@tar -czf $@ $(PYSOURCES) Makefile
	@echo -e $(Green)"Tar successfully created!"$(Color_Off)

$(PROGRAM): player.py
	cp $< $@
	chmod +x $@

.PHONY: clean all run

run: $(PROGRAM)
	-@./$<

clean:
	@rm -f $(PROGRAM).tar.gz $(PROGRAM)
	@echo -e $(Cyan)"Cleaning Complete!"$(Color_Off)
