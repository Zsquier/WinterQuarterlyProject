function [ ArrayColors ] = FindColors( InputMat )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
      
charCount = 0;
ArrayColors = [257:260];

for i = 1:32
    for j = 1:32
    if (ismember(InputMat(i,j,1), ArrayColors)) == false
       ArrayColors(charCount + 1) = InputMat(i,j,1);
       charCount = charCount + 1;
    end
    end
end
end

