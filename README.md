<h1 align="center">CSCTrie</h1>
<h2 align="center">CSC212 Final Project Trie</h2>

<p align="center">This is the main README.md for our final project.Dependencies, there are not really any.  C++11 and the source code.  The english.txt should be placed "../Trie/english.txt" from where the executable is.  It happened to be where our source code was.
  
</p>

<p align="center">So this is probably unorthadox but I rewrote the program to get it working as intended.  I strayed away from my original implementation and attemped to be high speed low drag. I had an issue with the unordered_map iterators when returning the pairs.
that was the initial plan to make the dotfile.  Search for the key "X,Y,Z" and return the corresping value in the pair (i.e. the pointer value_).  Use those with the node and label syntax and boom, dotfile.  It didn't work, the project was a disaster and I took the time 
to rewrite it.  As with the earlier implementation it uses some of the same headers and classes and the approach to the trie is similar but the fundamental portion of how child nodes are stored is simplifed.  I output some tries,
10, 25, 50 input tries to see what the graphs would look like.</p>
<br>
<br>
![10input](img/10input.png?raw=true "10 Input")

<br>
<br>
![25input](img/25input.png?raw=true "25 Input")

<br>
<br>
![50input](img/50input.png?raw=true "50 Input")