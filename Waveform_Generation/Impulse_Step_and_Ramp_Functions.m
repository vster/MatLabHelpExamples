t = (0:0.001:1)';
imp= [1; zeros(99,1)];       % Impulse
unit_step = ones(100,1);     % Step (with 0 initial cond.)
ramp_sig= t;                 % Ramp
quad_sig=t.^2;               % Quadratic
sq_wave = square(4*pi*t);    % Square wave with period 0.5