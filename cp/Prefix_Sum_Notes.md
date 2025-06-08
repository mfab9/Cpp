# 📌 Prefix Sum Arrays – Key Concepts & Takeaways

## 🧱 Building the Prefix Array

### ✅ 0-Based Prefix Array
```cpp
int a[n];
for(int i = 0; i < n; i++) cin >> a[i];
for(int i = 1; i < n; i++) a[i] += a[i-1];
// a[i] = sum of a[0] to a[i]
```
- Example:
  - Input: `{1, 2, 3}`
  - Prefix: `{1, 3, 6}`

---

### ✅ 1-Based Prefix Array
```cpp
int a[n+1] = {0};
for(int i = 1; i <= n; i++) cin >> a[i];
for(int i = 1; i <= n; i++) a[i] += a[i-1];
// a[0] = 0, and a[i] = sum of a[1] to a[i]
```
- Example:
  - Input: `{1, 2, 3}`
  - Prefix: `{0, 1, 3, 6}`

---

## 🎯 Extracting Range Sum

> ✅ **Formula:** `a[r] - a[l - 1]`  
> ✅ Make sure **prefix array** and **L/R query** are on the **same basis**

---

### 🔁 Case Handling

| Prefix Array Basis         | L/R Query Basis | What To Do                                           |
|----------------------------|------------------|------------------------------------------------------|
| 0-based (`a[0] = arr[0]`)  | 1-based          | Convert: `l--, r--` before using formula             |
| 1-based (`a[0] = 0`)       | 0-based          | Convert: `l++, r++` before using formula             |
| Same Basis (both 0 or 1)   | –                | Use directly: `a[r] - a[l - 1]`                      |

---

## 💡 Examples

### 🔹 0-Based Array + 1-Based Queries
```cpp
// Prefix array: 0-based
cin >> l >> r;
l--; r--; // Convert to 0-based
if (l == 0) cout << a[r] << endl;
else cout << a[r] - a[l - 1] << endl;
```

---

### 🔹 1-Based Array + 0-Based Queries
```cpp
// Prefix array: 1-based
cin >> l >> r;
l++; r++; // Convert to 1-based
cout << a[r] - a[l - 1] << endl;
```

---

### 🔹 Matching Basis (Best Case)
```cpp
// Both 1-based
cin >> l >> r;
cout << a[r] - a[l - 1] << endl;
```

---

## 🏁 Final Advice

- Prefer **1-based prefix arrays** with `a[0] = 0` for clean formulas and avoiding `if (l == 0)`
- Always **match the index basis** between the prefix array and queries before applying the formula.

---

📘 Happy Coding!
