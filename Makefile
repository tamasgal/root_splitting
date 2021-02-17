CXX := g++
CXXOPTS := -Wall
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --glibs)

default: write_files

TWhateverDct.cc: TWhatever.h TWhateverLinkDef.h
	rootcint -f $@ $(ROOTCFLAGS) $^

write_files: write_files.cxx TWhatever.h TWhateverLinkDef.h TWhateverDct.cc
	$(CXX) $(CXXOPTS) -o $@ $^ $(ROOTCFLAGS) $(ROOTLIBS)

clean:
	rm -f *Dct.cc *.pcm TWhateverDct.cc write_files
