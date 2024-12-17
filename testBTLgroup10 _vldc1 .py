import numpy as np
import matplotlib.pyplot as plt

# Hàm nhập dữ liệu an toàn, hỗ trợ biểu thức như 10^-9 
def safe_input(prompt):
    try:
        value = input(prompt)
        value = value.replace("^", "**")  # Replace '^' with '**' for exponentiation
        return float(eval(value))         # Evaluate the expression and convert to float
    except Exception as e:
        print(f"Lỗi: {e}. Vui lòng nhập lại một giá trị hợp lệ!")
        exit(1)

# Hàm nhập tọa độ và điện tích của các điện tích điểm
def input_charges(n):
    x = np.zeros(n)
    y = np.zeros(n)
    q = np.zeros(n)

    print("Nhập tọa độ và điện tích của các điện tích điểm:")
    for i in range(n):
        x[i] = safe_input(f"Nhập x{i+1}: ")
        y[i] = safe_input(f"Nhập y{i+1}: ")
        q[i] = safe_input(f"Nhập q{i+1}: ")
    return x, y, q

# Hàm nhập tọa độ và điện tích của điện tích thử q0
def input_qo():
    xo = safe_input("Nhập xo (m): ")
    yo = safe_input("Nhập yo (m): ")
    qo = safe_input("Nhập qo (Coulumb): ")
    return xo, yo, qo

# Chương trình chính
# Nhập số điện tích điểm
n = int(input("Nhập số điện tích điểm: "))

# Nhập tọa độ và điện tích của các điện tích điểm
x, y, q = input_charges(n)

# Nhập tọa độ và điện tích của điện tích thử q0
xo, yo, qo = input_qo()

# Hằng số Coulomb
k = 9e9

# Tính khoảng cách giữa các điện tích điểm và q0
r_qo = np.sqrt((x - xo)**2 + (y - yo)**2)

# Kiểm tra chia cho 0 nếu có khoảng cách r bằng 0
if np.any(r_qo == 0):
    raise ValueError("Khoảng cách r giữa điện tích và qo bằng 0! Kiểm tra tọa độ các điện tích.")

# Tính lực tĩnh điện do mỗi điện tích điểm tác dụng lên qo
F = k * qo * q / r_qo**2

# Tính các thành phần Fx và Fy của lực tĩnh điện
Fx = F * (x - xo) / r_qo
Fy = F * (y - yo) / r_qo

# Tính tổng hợp lực tĩnh điện
F_x = np.sum(Fx)
F_y = np.sum(Fy)
F_magnitude = np.hypot(F_x, F_y)

# In kết quả ra màn hình
print(f"Tổng hợp lực tĩnh điện: |F| = {F_magnitude:.3e} N")
print(f"Thành phần: Fx = {F_x:.3e} N, Fy = {F_y:.3e} N")

# Vẽ đồ thị biểu diễn lực tĩnh điện
plt.figure(figsize=(8, 6))
plt.title("Biểu diễn lực tĩnh điện")
plt.xlabel("x (m)")
plt.ylabel("y (m)")

# Vẽ các điện tích điểm
plt.scatter(x, y, color='blue', label="Điện tích điểm q")
plt.scatter(xo, yo, color='red', label="Điện tích qo")

# Vẽ vector lực tĩnh điện từ từng điện tích điểm
for i in range(n):
    plt.quiver(xo, yo, Fx[i], Fy[i], angles="xy", scale_units="xy", scale=1, color="green")

# Vẽ vector lực tổng hợp
plt.quiver(xo, yo, F_x, F_y, angles="xy", scale_units="xy", scale=1, color="red", label="Lực tổng hợp")

# Hiển thị chú thích và đồ thị
plt.legend()
plt.grid()
plt.axis("equal")
plt.show()
