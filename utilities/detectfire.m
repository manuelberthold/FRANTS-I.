function [imagebytes, firedetected] = detectfire(red, green, blue)
rgbImage = zeros(120,160,3, 'uint8');
    rgbImage(:,:,1) = uint8(red);
rgbImage(:,:,2) = uint8(green);
rgbImage(:,:,3) = uint8(blue);
imagebytes = rgbImage;

if  isempty(red) || length(red) < 2 || all(red(:)==0)
    firedetected = false;
  
else 

BW = extract_red_of_img(rgbImage);
BW_C = imclose(BW, strel('disk', 15));
BW_f = imfill(BW_C, 'holes');
if  isempty(BW_f) || all(BW_f(:)==0)
    firedetected = false;

else 
s = regionprops(BW_f);
maxVals = arrayfun(@(struct)max(struct.Area(:)),s);
[~, i] = max(maxVals);

boundbox = s(i).BoundingBox; 
width = boundbox(3);
height = boundbox(4);
    if (width > 55 && height > 145)
        imagebytes = insertObjectAnnotation(rgbImage, 'rectangle', s(i).BoundingBox, 'fire');
 
        firedetected = true;
    else
      
        firedetected = false;
    end
end
end
end 



