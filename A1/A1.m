function A1
time  = 10;
[x_pos, ~, y_pos, ~] = trajectory(50, time);
figure
hold on
plot(x_pos, y_pos, 'color', 'b')
title('Projectile Motion w v0 = 50')
hold off

time  = 10;
[x_pos, ~, y_pos, ~] = trajectory(20, time);
figure
hold on
plot(x_pos, y_pos, 'color', 'b')
title('Projectile Motion w v0 = 20')
hold off

% h = 0.01;
% A = [1 h 0 0; 0 1 0 0; 0 0 1 h; 0 0 0 1];
% B = [0; 0; 0; 0];
% k = [0; 0; 0; h*-g];
% disp(A);
% disp(B);
% disp(k);
end

function [x_pos, x_vel, y_pos, y_vel]=trajectory(v0, time)
x0=0;
y0=0;
alpha=45*(pi./180);
g=9.81;
t=0:0.01:time;
x_vel = v0*cos(alpha);
y_vel = v0*sin(alpha) - g*t;
x_pos = x0 + v0*cos(alpha)*t;
y_pos = y0 + v0*sin(alpha)*t-(g*t.^2)/2;
end