<h1 align="center">CSCTrie</h1>
<h2 align="center">CSC212 Final Project Trie</h2>

<p align="center">This is the main README.md for our final project.Dependencies, there are not really any.  C++11 and the source code.  The english.txt should be placed "../Trie/english.txt" from where the executable is.  It happened to be where our source code was.
  
</p>

<p align="center">So this is probably unorthadox but I rewrote the program to get it working as intended.  I wrote my second implementation (using std::unordered_map) and attemped to be high speed low drag. 
This proved to be a massive failure and I shouldn't and tried it in the first place.  I had an issue with the unordered_map iterators when returning the pairs.
that was the initial plan to make the dotfile.  Search for the key "X,Y,Z" and return the corresping value in the pair (i.e. the pointer value) use those with the node and label syntax and boom, dotfile.  It didn't work, the project was a disaster and I took the time 
to rewrite it (although I doubt anyone will see this besides me).  As with the earlier implementation it uses some of the same headers and classes and the approach to the trie is similar but the fundamental portion of how child nodes are stored is simplifed.  I output some tries,
10, 25, 50 input tries to see what the graphs would look like.</p>

The new version outputs 3 .txt with .dot syntax (the txt files were just for simplicity on my end to copy and paste into online graphers quickly). <br>
It also outputs 2 .m files for matlab that are plug and play for graphs for total input time vs input count. <br>
The other .m file is a graph for search time vs input word length.  They both use 42000+ values so take a bit of time to graph if using the online version of matlab.<br>

<br>
<br>
<img src="img/10input.png">

<br>
<br>
<img src="img/25input.png">

<br>
<br>
<img src="img/50input.png">