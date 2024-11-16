# Установка разделителя для CSV
set datafile separator ","

set style line 1 lt 2 lw 1 lc rgb "green"
set style line 2 lt 2 lw 1 lc rgb "blue"
set style line 3 lt 2 lw 1 lc rgb "red"

# --- График перемещения (target) ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "./plots/Trajectory_target.png"
set title "Траектория"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
# set xrange [-50000:50000] 
# set yrange [-50000:50000]
# set zrange [0:50000]
set grid
splot "./values/target_values.csv" using 1:2:3 with lines linestyle 1 title "Траектория"
set output

# График зависимости скорости от времени (target)
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "./plots/Speed_target.png"
set title "Зависимость скорости от времени"
set xlabel "t"
set ylabel "V"
set xrange [0:150] 
set yrange [0:500]
set grid
plot "./values/target_values.csv" using 4:5 with lines linestyle 2 title "Скорость"
set output

# --- График перемещения (uav) ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "./plots/Trajectory_uav.png"
set title "Траектория"
set xlabel "X"
set ylabel "Z"
set zlabel "Y"
set xrange [-50000:50000] 
set yrange [-50000:50000]
set zrange [0:50000]
set grid
splot "./values/uav_values.csv" using 1:3:2 with lines linestyle 3 title "Траектория"
set output

# График зависимости скорости от времени (uav)
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "./plots/Speed_uav.png"
set title "Зависимость скорости от времени"
set xlabel "t"
set ylabel "V"
set xrange [0:150] 
set yrange [0:5000]
set grid
plot "./values/uav_values.csv" using 4:5 with lines linestyle 1 title "Скорость"
set output