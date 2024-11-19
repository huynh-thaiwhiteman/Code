import numpy as np
import matplotlib.pyplot as plt
from sympy import symbols, Eq, solve

# Nhập số điện tích điểm
n = int(input("Nhập số điện tích điểm: "))

# Nhập tọa độ và điện tích của các điện tích điểm
def input_charges(n):
    x = np.zeros(n)
    y = np.zeros(n)
    q = np.zeros(n)

    print("Nhập tọa độ và điện tích của các điện tích điểm:")
    for i in range(n):
    x[i] = float(input(f"Nhập x{i+1}: "))
    y[i] = float(input(f"Nhập y{i+1}: "))
    q[i] = float(input(f"Nhập q{i+1}: "))
    return x, y, q

# Nhập số lượng điện tích điểm
    n = int(input("Nhập số điện tích điểm: "))
    x, y, q = input_charges(n)

# Nhập tọa độ và điện tích của điện tích điểm qo
def input_qo():
xo = float(input("Nhập xo(m): "))
yo = float(input("Nhập yo(m): "))
qo = float(input("Nhập qo(Coulumb): "))

# Hằng số Coulomb
k = 9 * (10 ** 9)

# Tạo vector vị trí của các điện tích điểm
r = np.array([x, y])

# Tính khoảng cách giữa các điện tích điểm và qo
r_qo = np.sqrt((x - xo)**2 + (y - yo)**2)

# Kiểm tra và xử lý chia cho 0 nếu bất kỳ r_qo nào bằng 0
if np.any(r_qo == 0):
    raise ValueError("Khoảng cách r giữa điện tích và q0 bằng 0! Kiểm tra tọa độ các điện tích.")

# Tính lực tĩnh điện do mỗi điện tích điểm tác dụng lên qo
F = k * qo * q / r_qo**2

# Tính thành phần Fx, Fy của lực tĩnh điện
Fx = F * (x - xo) / r_qo
Fy = F * (y - yo) / r_qo

# Tính tổng hợp lực tĩnh điện
F_x = np.sum(Fx)
F_y = np.sum(Fy)

F_magnitude = np.hypot(F_x, F_y)  # np.hypot tự tính sqrt(F_x**2 + F_y**2)

# In kết quả
print(f"Tổng hợp lực tĩnh điện: |F| = {F_magnitude:.3e} N")
print(f"Thành phần: Fx = {F_x:.3e} N, Fy = {F_y:.3e} N")

# Vẽ đồ thị biểu diễn lực tĩnh điện
plt.figure(figsize=(8, 6))
plt.title("Biểu diễn lực tĩnh điện")
plt.xlabel("x (m)")
plt.ylabel("y (m)")

# Vẽ các điện tích điểm
plt.scatter(x, y, color='blue', label="Điện tích điểm q")
plt.scatter(xo, yo, color='red', label="Điện tích điểm qo")

# Vẽ vector lực tĩnh điện
for i in range(n):
    plt.quiver(xo, yo, Fx[i], Fy[i], angles="xy", scale_units="xy", scale=1, color="green")

# Vẽ vector tổng hợp lực
plt.quiver(xo, yo, F_x, F_y, angles="xy", scale_units="xy", scale=1, color="red", label="Lực tổng hợp")

# Hiển thị chú thích và đồ thị
plt.legend()
plt.grid()
plt.axis("equal")  # Đảm bảo tỷ lệ x:y trên đồ thị
plt.show()
