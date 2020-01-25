function detected = detectfire(red, green, blue)
if  isempty(red) || length(red) < 2 || all(red(:)==0)
    detected = false;
    
else 
    
    %%I = imread('fire2.jpg');
BW = extract_red(red, green, blue);
BW_C = imclose(BW, strel('disk', 15));
BW_f = imfill(BW_C, 'holes');
if  isempty(BW_f) || all(BW_f(:)==0)
    detected = false;
else 
s = regionprops(BW_f);
maxVals = arrayfun(@(struct)max(struct.Area(:)),s);
[~, i] = max(maxVals);

boundbox = s(i).BoundingBox; 
width = boundbox(3);
height = boundbox(4);
    if (width > 55 && height > 145)
     detected = true;
    else
        detected = false;
    end
end
end
end 



