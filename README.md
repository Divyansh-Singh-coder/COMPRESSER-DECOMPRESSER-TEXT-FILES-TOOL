# COMPRESSER-DECOMPRESSER-TEXT-FILES-TOOL

*COMPANY: CODETECH IT SOLUTIONS

*NAME: DIVYANSH

*INTERN ID: CT04DR1854

*DOMAIN: C PROGRAMMING

*DURATION: 4 WEEKS

*MENTOR: NEELA SANTOSH

#ABOUT TASK 4:-

This project is a simple Text Compression and Decompression Tool made using the Run-Length Encoding (RLE) technique in the C programming language. The aim of this tool is to reduce the size of text files by compressing repeated characters and then recover the original data back through decompression. This project demonstrates the concepts of file handling, data encoding, command-line arguments, and algorithmic thinking in a very clear way. It is one of the best practical tasks because it teaches how files can be processed, how patterns can be detected, and how data can be stored more efficiently.

Run-Length Encoding (RLE) is a basic compression method in which repeated characters are replaced with a single character followed by the number of times it appears. For example, the text "aaaaabbcc" will be encoded as "a5 b2 c2". This reduces the file size when the text contains long sequences of repeated characters. RLE is simple, fast, and memory-efficient, which makes it useful in many basic compression tools, simple image formats, and text processing tasks.

In this project, the user provides input files and output files through command-line arguments. If the user chooses the compress mode, the program reads the input file character by character. It checks how many times a character is repeated continuously. Instead of writing each repetition separately, the program writes only one copy of the character and then writes the count of repetitions. This helps in saving storage space. The program uses proper file handling functions like fopen, fgetc, fputc, and fprintf to manage reading and writing operations. It also properly handles edge cases such as empty files, end-of-file conditions, and maximum repetition limits.

The decompression mode works in the opposite way. It reads the compressed file and extracts the character followed by the number that represents how many times it appeared originally. The program repeats that character back into the output file the exact number of times. This helps in reconstructing the original file without losing any information. If no number is found after a character, the program assumes the character appears once. The decompression logic ensures that the data is exactly restored to its original form, making this tool a lossless compression method.

This tool demonstrates how file formats can be transformed, how encoding works, and how data can be reduced in size using pattern-based approaches. It also shows the importance of validation, error handling, and robust file operations. In real systems, more advanced compression algorithms are used, but RLE helps beginners understand the fundamental ideas behind compression. It is widely used in early image formats like PCX, simple BMP icons, and basic text compression utilities.

Overall, this project improves understanding of file handling, loops, character processing, buffers, and real-world use of algorithms. It also helps students learn how to build command-line tools that can take parameters and generate output files. The Compress & Decompress Text Tool using RLE is a great beginner-level project because it is simple to understand, easy to test, and demonstrates a complete pipeline — input, processing, and output.

#OUTPUT IMAGE:-<img width="1913" height="1009" alt="Image" src="https://github.com/user-attachments/assets/09d81b28-62d6-4a02-b515-a030f61d1b3b" />
