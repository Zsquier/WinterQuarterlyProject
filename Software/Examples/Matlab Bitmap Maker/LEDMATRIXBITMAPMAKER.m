clc
clear all

%read in the bitmap image as a matrix and preallocate memory to variable B
A = imread('BMPLOGO.bmp');
B = zeros(32,32);

%call a function to identify the four unique colors of the bitmap, and
%store the unique values of their red components
charKeys = FindColors(A);

%this function cycles through the input image and maps each unique red
%component of the bitmap to the numbers 0:3, or binary 00:11
for i=1:32
   for j=1:32      
        if A(i,j,1) == charKeys(1);
          B(i,j) = 00;
        elseif A(i,j) == charKeys(2);
          B(i,j) = 1;
        elseif A(i,j) == charKeys(3);
          B(i,j) = 2;            
        elseif A(i,j) == charKeys(4);
          B(i,j) = 3;                    
        else
          %this is just a flag to note if colors were assigned wrong
          s=5;
        end
   end
end

%this loop cycles through the matrix of 0:3, and combines every group of
%four numbers in a row into a single byte using bit shifting and adding
for h=1:32;
    for k=1:8;
        %the first number in a group of 4 is assigned the top two bits, and
        %each subsequent number is assigned the following two bits
        nib1 = bitshift(uint8(B(h,(4*k)-3)),6);
        nib2 = bitshift(uint8(B(h,(4*k)-2)),4);
        nib3 = bitshift(uint8(B(h,(4*k)-1)),2);
        nib4 = uint8(B(h,4*(k-0)));
        M(h,k) = nib1+nib2+nib3+nib4;
    end
end

%this just loops through and saves everything in hexadecimal
for o =1:32
    for y = 1:8
        hexOut{o,y} = dec2base(M(o,y),16); 
    end
end

%prep the delimiting chars and open a text file for output
A = char('0x');
C = char(',');
filecount = 1;
file = fopen('OutputFile.txt','w');

%this has to be some of the worst, grossest code I've ever written
%i'm sorry
for op = 1:32
for m = 1:8
    %we concatinate delimiters to the hex values for each one of these and
    %store them in a cell matrix called outputFile
    temp = [sprintf([A,hexOut{op,m},C])];
    outputFile{op,filecount} = temp;
    filecount = filecount +1;
end
%at the end of each row we call for a newline
outputFile{op,filecount} = '\n';
for l = 1:9
    %each cell gets printed to the output file one by one. I spent like
    %half an hour trying to find a workaround but I couldnt figure it out
    fprintf(file,outputFile{op,l});
end
filecount = 1;
end
%close the file, send to arduino code
fclose(file);