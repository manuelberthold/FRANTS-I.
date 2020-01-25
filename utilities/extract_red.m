function [BW] = extract_red(red, blue, green)
%createMask  Threshold RGB image using auto-generated code from colorThresholder app.
%  [BW,MASKEDRGBIMAGE] = createMask(RGB) thresholds image RGB using
%  auto-generated code from the colorThresholder app. The colorspace and
%  range for each channel of the colorspace were set within the app. The
%  segmentation mask is returned in BW, and a composite of the mask and
%  original RGB images is returned in maskedRGBImage.

% Auto-generated by colorThresholder app on 08-Mar-2019
%------------------------------------------------------


% Convert RGB image to chosen color space


% Define thresholds for channel 1 based on histogram settings
channel1Min = 215.000;
channel1Max = 255.000;

% Define thresholds for channel 2 based on histogram settings
channel2Min = 0.000;
channel2Max = 255.000;

% Define thresholds for channel 3 based on histogram settings
channel3Min = 0.000;
channel3Max = 255.000;

% Create mask based on chosen histogram thresholds
sliderBW = (red >= channel1Min ) & (red <= channel1Max) & ...
    (green >= channel2Min ) & (green <= channel2Max) & ...
    (blue >= channel3Min ) & (blue <= channel3Max);
BW = sliderBW;


end
%   Copyright 2019 The MathWorks, Inc.
