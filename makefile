captsurvey: main.cpp libcaptsurvey.so libcapt.so
	g++ -Wall -std=c++11 -o captsurvey main.cpp -ldl

libcapt.so: LibCapt/ICapt.cpp
	g++ -Wall -std=c++11 -shared -o libcapt.so LibCapt/ICapt.cpp -I.

libcaptsurvey.so: PluginCaptSurvey/PluginSurvey.cpp
	g++ -Wall -std=c++11 -shared -o libcaptsurvey.so PluginCaptSurvey/PluginSurvey.cpp -I. -lcapt
 
clean:
	rm -f captsurvey libcaptsurvey.so libcapt.so