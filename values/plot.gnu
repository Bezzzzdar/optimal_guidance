# Установка разделителя для CSV
set datafile separator ","

# --- График перемещения ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "Trajectory.png"
set title "Перемещение"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid

# Отображаем и сохраняем график
splot "target_values.csv" using 1:2:3 with linespoints title "Траектория"

# Закрываем файл с изображением
set output

# --- График зависимости скорости от времени ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "Speed.png"
set title "Зависимость скорости от времени"
set xlabel "Время"
set ylabel "Скорость"
set grid

# Отображаем и сохраняем график
plot "target_values.csv" using 5:4 with linespoints title "Скорость"

# Закрываем файл с изображением
set output