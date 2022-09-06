C = csvread('1234.csv');
dt = (0.02047);
fs=1/dt;
N=2000;
figure
plot(C(1:N,1),C(1:N,2));

t = C(1:N,2);
t_f = fft(t);
m = length(t_f);
freq = (-m/2:(m/2-1))*fs/(m-1);
figure
plot(freq,fftshift(abs(t_f))/N);