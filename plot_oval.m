function plot_oval
    clear, clc, close;

    x = zeros(100, 1);
    y = zeros(100, 1);
    t = 0;
    for i=1:75
        x(i) = 1 * cos(t);
        y(i) = 1 * sin(t + 0.5);
        t = t + (0.0838);
    end
    figure, plot(x, y, '+')
end