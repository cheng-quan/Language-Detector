main: main.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp 
	g++ main.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp -o main

train: train.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp
	g++ train.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp -o train

test: test.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp
	g++ test.cpp LanguageDetector.cpp Trigram.cpp Trie.cpp -o test

clean:
	rm main
	rm train
	rm test
