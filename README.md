# Inverted-Search-Project

The Inverted Search Project is a data structures–based application developed in C that implements an efficient word-searching mechanism using the concept of inverted indexing.
The primary objective of this project is to create a searchable database from multiple text files and enable fast retrieval of information.

In this system, data is organized in an inverted format where each word is mapped to the list of files in which it appears along with its frequency of occurrence. The project uses a hash table combined with linked lists to efficiently store and manage indexed data.

The hashing technique enables quick access to words based on their initial character, reducing search time and improving overall performance.

Features:

   Create searchable database from multiple text files
   
   Fast word searching using inverted indexing.
   
   Displays file names and frequency of word occurrence.
   
   Efficient data storage using hash tables and linked lists.
   
   Save and update database functionality.
   
   Dynamic memory allocation for flexible storage.
   
   Efficient file handling and string processing.
   
Working Principle:->
 
      Inverted Indexing

Instead of storing data file by file, the system stores each word along with:

          The files containing the word.
          
          Number of occurrences in each file.
          
Hashing Technique:

   Words are indexed using hash values based on their initial characters, allowing faster search and retrieval operations.

Linked Lists:

Linked lists are used to manage collisions and dynamically store file information associated with each word.

Technologies Used:->
    C Programming Language
    
    Hash Tables
    
    Linked Lists
    
    Dynamic Memory Allocation
    
    File Handling
    
    String Manipulation
    
Concepts Demonstrated:

This project provides practical understanding of:

    Hashing techniques
    
    Inverted indexing
    
    Dynamic data structures
    
    File processing in C
    
    Search optimization

    Memory management
    
Applications:->
    Search Engines
    
   Document Retrieval Systems
   
   Text Processing Applications
  
   Information Retrieval Systems

Conclusion:

The Inverted Search Project demonstrates how data structures and indexing techniques can be used to build fast and efficient search systems. It strengthens understanding of hashing, linked lists, and file handling while showcasing real-world applications of data structures.
