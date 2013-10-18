sbrts
=====

---BUILDING AND RUNNING THE PROJECT---

-- Basic instructions (work for text editors, but read them whatever you use) --

In case you only use a text editor (Gedit, VIM) there's just a few things to know:

- To generate Makefiles, make a directory at the repository's parent directory, call it build, go into it and do "cmake ../repository_name",
this will call CMake using the "CMakelists.txt" file in the repository (the root directory of the project)
but will generate all the build files needed into "build/", this way you'll not pollute the repository
with generated build files.

- Once the build files are generated, and while you still are in "build/", you can build the project using "make",
this will use the generated Makefiles to build the project executable "Main" into "bin/" (this and various
object files in "build/")

- To properly run the executable, go into build/bin/, and call it with "./Main", 




-- Using Netbeans --

Basic instructions are still true if you use an IDE, the thing here is to do what we did manually by using
Netbeans's user interface:

- Go into "File > New Project...", choose C/C++ Project with Existing Sources, then press "Next"

- Chose the "Automatic" configuration mode (if it's not default) and browse the folder that contains the
existing sources (sbrts/), Netbeans might have found your CMakelists.txt file at this stage, so you can
press "finish".

- Netbeans has now use CMake to build the project, good stuff ! Oh but wait, it made some mess by generating
those temporary files in the root directoty of the project, don't worry, we will tell him to do it in "build/"
instead from now on ! (you can remove "CMakeCache.txt", "CMakeFiles/", "Makefile" and "cmake_install.cmake")

- In the "Projects" panel, right click on "sbrts" go in "properties", once in the Project Properties, go into "Make"
(extend Build if needed) and set the Working Directory to "./build" and Build Result to "./bin/Main", then go in "Run"
to set the Run Directory to "./src", click OK to validate the settings.

- In the Projects panel, right click on the "CMakeLists.txt" file, choose Properties then set de "build/" directory
as Run Directory, you should have something like "path/to/the/project/sbrts/build") and and ".." in the Arguments
(that should give you something like ".. -G "Unix Makefiles" etc..."), right click on "CMakeLists.txt" and then
"Generate MakeFile".

- At this stage, Netbeans is able to build and run the project  correctly using CMakeLists.txt, congrats !


-- Using Code::Blocks --

Code::Blocks use its very own kind of project file (with the .cbp extension), fortunately CMake is kind enough to
let you generate such file ! let's do so:

- Go in the "build/" folder, and do 'cmake .. -G "CodeBlocks - Unix Makefiles"', which have a similar effect to the first thing
we do in the Basic Instructions, but here we generate a SBRTS.cbp file additionally, which can ben opened with Code::Blocks !

- Open Code::Blocks, go into "File > Open", and open "build/SBRTS.cbp", you should be able to build the project, but not properly
run it yet, to do so right click on "SBRTS" in the right panel, Properties, then go into Build targets and select "Main", finally
in Execution working dir set "path/to/project/sbrts/src", this will tell Code::Blocks to run the executable from "src/".

- You can now build and run the project using Code::Blocks, congrats !

-- Generate the doc

To generate the doc, you need to install 'doxygen' and 'graphviz' packages.
Then, simply do 'doxygen Doxyfile' in the repo's directory. This will generate the documentation in HTML in directory 'doc/html'
