# Установка разделителя для CSV
set datafile separator ","

# --- График перемещения (target) ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "./plots/Trajectory_target.png"
set title "Траектория"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid
splot "./values/target_values.csv" using 1:2:3 with linespoints title "Траектория"
set output

# График зависимости скорости от времени (target)
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "./plots/Speed_target.png"
set title "Зависимость скорости от времени"
set xlabel "t"
set ylabel "V"
set grid
plot "./values/target_values.csv" using 5:4 with linespoints title "Скорость"
set output

# --- График перемещения (uav) ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "./plots/Trajectory_uav.png"
set title "Траектория"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid
splot "./values/uav_values.csv" using 1:2:3 with linespoints title "Траектория"
set output

# График зависимости скорости от времени (uav)
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "./plots/Speed_uav.png"
set title "Зависимость скорости от времени"
set xlabel "t"
set ylabel "V"
set grid
plot "./values/uav_values.csv" using 5:4 with linespoints title "Скорость"
set output