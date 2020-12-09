inputsize = [10, 50, 100, 500, 1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000, 25000];
inserttime = [152, 280, 688, 3079, 8070, 16233, 36779, 44011, 63968, 79529, 77423, 104898, 125104, 152148];
x = (10:25000);
y1 = (5.9892 * x) + 975.5;
plot(inputsize, inserttime, 'o')
xlabel 'Amount of Words'
ylabel 'Time (microseconds)'
grid on
grid minor
hold on;
plot(x,y1,'--')
hold on
searchtime = [465, 540, 501, 558, 631, 1661, 990, 1183, 1540, 996, 1019, 765, 909, 920];
y2 = (0.0119 * inputsize) + 806.69;
plot(inputsize, searchtime, 'ro' )
hold on;
plot(inputsize,y2,'--')
legend('Insertion Time', 'Insertion Trendline', 'Search Time', 'Search Treadline', 'location', 'northwest')