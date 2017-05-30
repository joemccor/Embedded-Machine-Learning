
%initialize variables
cx = 0;
cy = 0;
xd = 0;
yd = 0;

%get webcam object
cam = webcam(1);

% oper serial port for communication
% s=serial('COM4', 'BaudRate', 115200);
% s.Terminator = 'LF';
% fopen(s);


%%
while(1)
    datevec(now);
    starttime = ans(6);
    %
    %get current mouse position, this is the desired location of the 
    
    %get snapshot from webcam
    snap = snapshot(cam);
    
%     mousePosition = get(0,'pointerlocation');
%     xd = mousePosition(1);
%     yd = mousePosition(2);
    
    
    
    %find where red ball is
    mask = snap(:,:,1)>(snap(:,:,2) + snap(:,:,3));
    cx = 0; cy = 0; count = 0;
    for x = 1:size(mask,2)
        for y = 1:size(mask,1)
            if(mask(y,x) == 1)
                cx = cx + x;
                cy = cy + y;
                count = count + 1;
            end
        end
    end
    %mask = uint8(mask);
    
%     imshow(mask*255);
    
    %map coords to table, max distance of 100, min of -100. 0 is center
    
    cx = cx / count;
    cy = cy / count;
    cx = round((cx - 340)/1);
    cy = round((cy - 230)/1);
    
    [cx, cy, xd, yd]
    
%     cx = 1.0;cy=1.0;xd=1.0;yd=2.0;
    %send data to Propeller
    toSend = ['x:' num2str(cx) '!y:' num2str(cy) '!'];%X:' num2str(xd) '!Y:' num2str(yd) '!'
    toSend;
    delay = 0.02;
    
    for c = toSend
        if c == '!'
%             fprintf(s, '\n');
        else
%             fprintf(s, '%c', c);
        end
        pause(delay);
    end
    
    datevec(now);
    endtime = ans(6);
    endtime - starttime
end
%%
toSend = ['P:0.9!I:0.0!D:0.0!'];
toSend;
delay = 0.02;
    
for c = toSend
	if c == '!'
	fprintf(s, '\n');
    else
        fprintf(s, '%c', c);
    end
    pause(delay);
end
%%

toSend = ['R:0!'];
toSend;
delay = 0.02;
    
for c = toSend
	if c == '!'
	fprintf(s, '\n');
    else
        fprintf(s, '%c', c);
    end
    pause(delay);
end
%%
fscanf(s)

%%

%close all and clean up
% fclose(s)
% delete(s)
% clear s
clear all
