#include <iostream>
using namespace std;

                    int Sonhonhat2so(int num1, int num2) {
                        return (num1 < num2) ? num1 : num2;
                    }

                    int UCLN(int a, int b) {
                        while (b != 0) {
                            int temp = b;
                            b = a % b;
                            a = temp;
                        }
                        return a;
                    }

                    int BCNN(int a, int b) {
                        return (a * b) / UCLN(a, b);
                    }

                    // Hàm tính giai thừa (n!)
                    int GiaiThua(int n) {
                        if (n <= 1) {
                            return 1; // Giai thừa của 0 và 1 đều bằng 1
                        }

                        int resultgt = 1;
                        for (int i = 2; i <= n; i++) {
                            resultgt *= i;
                        }
                        return resultgt;
                    }

                    // Hàm tính X mũ n (X^n) không dùng đệ quy
                    double TinhXmuN(double X, int n) {
                        double result = 1.0;

                        if (n < 0) {
                            X = 1.0 / X;
                            n = -n;
                        }

                        while (n > 0) {
                            if (n % 2 == 1) {
                                result *= X;
                            }
                            X *= X;
                            n /= 2;
                        }

                        return result;
                    }
                // - Tính n! (n>1): n!= 1*2* ...*(n-1)*n // Tính tổ hợp C(n,k) = n! / k!(n-k)!
                int tichGiaiThua (int num){
                    if (num <= 1){
                        return 1;
                    }
                    int tich = 1;
                    for (int i = 2; i <= num; i++){
                        tich *= i;
                    }
                    return tich;
                }
                int tinhToHop(int n, int k) {
                    if (k < 0 || k > n) {
                        return 0; 
                    }
                    int giaiThuaN = tichGiaiThua(n);
                    int giaiThuaK = tichGiaiThua(k);
                    int giaiThuaNK = tichGiaiThua(n - k);

                    int toHop = giaiThuaN / (giaiThuaK * giaiThuaNK);
                    return toHop;
                }
                    // Hàm tính chu vi hình chữ nhật
                    int TinhChuVi(int dai, int rong) {
                        return 2 * (dai + rong);
                    }

                    // Hàm tính diện tích hình chữ nhật
                    int TinhDienTich(int dai, int rong) {
                        return dai * rong;
                    }

                    // Hàm vẽ hình chữ nhật bằng các dấu '*'
                void VeHCB(int dai, int rong) {
                    for (int i = 0; i < rong; i++) { // Lặp theo chiều ngang trước
                        for (int j = 0; j < dai; j++) { // Lặp theo chiều dọc
                            if (i == 0 || i == rong - 1 || j == 0 || j == dai - 1) {
                                cout << "* ";
                            } else {
                                cout << "  ";
                            }
                        }
                        cout << endl;
                    }
                }
                        // Hàm kiểm tra một số có phải là số hoàn thiện hay không
                    bool KTSoHoanThien(int n) {
                        int sum = 1; // Khởi tạo sum bằng 1 vì số hoàn thiện luôn có ước số 1

                        for (int i = 2; i <= n / 2; i++) {
                            if (n % i == 0) {
                                sum += i;
                            }
                        }

                        return sum == n;
                    }

                    // Hàm in ra tất cả các số hoàn thiện nhỏ hơn số N cho trước
                    void InRaSHT(int N) {
                        cout << "Cac so hoan thien nho hon " << N << " la: ";
                        for (int i = 2; i < N; i++) {
                            if (KTSoHoanThien(i)) {
                                cout << i << " ";
                            }
                        }
                        cout << endl;
                    }
                        
                    // Hàm tính số tờ tiền của từng loại tiền để tổng bằng amount
                    void calculateCurrency(int amount, int &num50000, int &num20000, int &num10000, int &num5000, int &num2000, int &num1000) {
                        // Ban đầu, số tờ tiền của mỗi loại là 0
                        num50000 = num20000 = num10000 = num5000 = num2000 = num1000 = 0;

                        // Sử dụng thuật toán vét cạn để tìm số tờ tiền của từng loại
                        while (amount >= 50000) {
                            amount -= 50000;
                            num50000++;
                        }

                        while (amount >= 20000) {
                            amount -= 20000;
                            num20000++;
                        }

                        while (amount >= 10000) {
                            amount -= 10000;
                            num10000++;
                        }

                        while (amount >= 5000) {
                            amount -= 5000;
                            num5000++;
                        }

                        while (amount >= 2000) {
                            amount -= 2000;
                            num2000++;
                        }

                        while (amount >= 1000) {
                            amount -= 1000;
                            num1000++;
                        }
                    }
                    int DaoKiSo(int n) {
                    int reversedNumber = 0;

                    while (n > 0) {
                        int digit = n % 10;        // Lấy chữ số cuối cùng
                        reversedNumber = reversedNumber * 10 + digit; // Đảo vị trí các chữ số
                        n /= 10;                  // Loại bỏ chữ số cuối cùng
                    }

                    return reversedNumber;
                }
                // Hàm kiểm tra tính hợp lệ của ngày và tháng
                bool isValidDate(int day, int month, int year) {
                    if (year < 1 || month < 1 || month > 12 || day < 1) {
                        return false;
                    }

                    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

                    // Năm nhuận có 29 ngày tháng 2
                    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                        daysInMonth[1] = 29;
                    }

                    return day <= daysInMonth[month - 1];
                }

                // Hàm tính số ngày trong tháng đã nhập
                int getDaysInMonth(int month, int year) {
                    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

                    // Năm nhuận có 29 ngày tháng 2
                    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                        daysInMonth[1] = 29;
                    }

                    return daysInMonth[month - 1];
                }

                // Hàm tính ngày hôm sau
                void getNextDate(int& day, int& month, int& year) {
                    int daysInMonth = getDaysInMonth(month, year);

                    day++;
                    if (day > daysInMonth) {
                        day = 1;
                        month++;
                        if (month > 12) {
                            month = 1;
                            year++;
                        }
                    }
                }

                // Hàm tính ngày hôm trước
                void getPreviousDate(int& day, int& month, int& year) {
                    day--;
                    if (day < 1) {
                        month--;
                        if (month < 1) {
                            month = 12;
                            year--;
                        }
                        day = getDaysInMonth(month, year);
                    }
                }
                void printSportEvents(int startYear, int endYear) {
                    for (int year = startYear; year <= endYear; year++) {
                        if ((year - 1988) % 4 == 0) {
                            cout << year << " - Olympic & Euro" << endl;
                        }
                        if ((year - 1990) % 4 == 0) {
                            cout << year << " - World Cup" << endl;
                        }
                        if ((year - 1995) % 2 == 0) {
                            cout << year << " - SEA Games" << endl;
                        }
                        if ((year >= 1996) && (year - 1996) % 2 == 0) {
                            cout << year << " - Tiger Cup" << endl;
                        }
                    }
                }

                // Hàm đọc một số (chỉ nhận số có một chữ số)
                string readSingleDigitNumber(int number) {
                    switch (number) {
                        case 0: return "khong";
                        case 1: return "mot";
                        case 2: return "hai";
                        case 3: return "ba";
                        case 4: return "bon";
                        case 5: return "nam";
                        case 6: return "sau";
                        case 7: return "bay";
                        case 8: return "tam";
                        case 9: return "chin";
                        default: return "So khong hop le!";
                    }
                }

                // Hàm đọc số có 3 chữ số
                string readThreeDigitNumber(int number) {
                    int hundred = number / 100;
                    int ten = (number / 10) % 10;
                    int unit = number % 10;

                    string result;

                    if (hundred > 0) {
                        result += readSingleDigitNumber(hundred) + " tram ";
                    }

                    if (ten > 1) {
                        result += readSingleDigitNumber(ten) + " muoi ";
                    } else if (ten == 1) {
                        result += "muoi ";
                    }

                    if (ten != 1 && unit > 0) {
                        result += readSingleDigitNumber(unit);
                    }

                    return result;
                }

                // Hàm đọc số nhỏ hơn 1 000 000
                string readNumberLessThanOneMillion(int number) {
                    if (number < 10) {
                        return readSingleDigitNumber(number);
                    } else if (number < 100) {
                        return readSingleDigitNumber(number / 10) + " muoi " + readSingleDigitNumber(number % 10);
                    } else if (number < 1000) {
                        return readThreeDigitNumber(number);
                    } else if (number < 1000000) {
                        int thousands = number / 1000;
                        int remainder = number % 1000;
                        return readThreeDigitNumber(thousands) + " nghin " + readThreeDigitNumber(remainder);
                    } else {
                        return "So khong hop le!";
                    }
                }
                //Hàm chuẩn hóa số điện thoại
                string standardizePhoneNumber(const string& input) {
                    string result;

                // Xóa tất cả các ký tự không phải chữ số khỏi chuỗi đầu vào
                    for (char c : input) {
                        if (isdigit(c)) {
                            result += c;
                        }
                    }

                    return result;
                }
                int timGiaTriLonNhat(int arr[], int n) {
                int maxVal = arr[0]; 
                for (int i = 1; i < n; i++) {
                    if (arr[i] > maxVal) {
                        maxVal = arr[i]; 
                    }
                }
                return maxVal;
            }
            int timViTriGiaTriLonNhat(int arr[], int n) {
                int maxVal = arr[0];
                int maxIndex = 0;
                for (int i = 1; i < n; i++) {
                    if (arr[i] > maxVal) {
                        maxVal = arr[i];
                        maxIndex = i;
                    }
                }
                return maxIndex;
            }
            void chenGiaTriTruocGiaTriLonNhat(int arr[], int &n, int m) {
                // lấy vị trí của max trước
                int maxIndex = timViTriGiaTriLonNhat(arr, n);

                for (int i = n - 1; i >= maxIndex; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[maxIndex] = m;
                n++; 
            }
            void sapXepPhanTuAmVeDauDay(int arr[],int &n)
            {
                int left = 0; // Con trỏ trỏ tới phần tử đầu tiên của dãy
                int right = n - 1; // Con trỏ trỏ tới phần tử cuối cùng của dãy

                while (left < right) {
                    // Di chuyển con trỏ left sang phải cho đến khi gặp phần tử dương hoặc bằng 0
                    while (left < right && arr[left] < 0) {
                        left++;
                    }

                    // Di chuyển con trỏ right sang trái cho đến khi gặp phần tử âm
                    while (left < right && arr[right] >= 0) {
                        right--;
                    }

                    // Nếu left < right, gặp phần tử cần đổi chỗ
                    if (left < right) {
                        int temp = arr[left];
                        arr[left] = arr[right];
                        arr[right] = temp;
                    }
                }
            }
            // Hàm kiểm tra xem vị trí (x, y) có nằm trong ma trận hay không
bool isValid(int x, int y, int M, int N) {
    return (x >= 0 && x < M && y >= 0 && y < N);
}

// Hàm thực hiện thống kê các trường hợp có nguy cơ lây nhiễm
int countPotentialInfections(int M, int N, int A[100][100]) {
    int potentialInfections = 0;

    // Duyệt qua từng ô trong ma trận
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // Nếu ô hiện tại là bệnh nhân (-1)
            if (A[i][j] == -1) {
                // Duyệt qua 8 ô xung quanh (dx, dy) của ô bệnh nhân
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        // Bỏ qua ô hiện tại
                        if (dx == 0 && dy == 0)
                            continue;

                        // Tính toán tọa độ (x, y) của ô xung quanh
                        int x = i + dx;
                        int y = j + dy;

                        // Nếu ô xung quanh nằm trong ma trận và có giá trị >= 0, tăng biến đếm potentialInfections lên 1
                        if (isValid(x, y, M, N) && A[x][y] >= 0) {
                            potentialInfections++;
                        }
                    }
                }
            }
        }
    }

    return potentialInfections;
}
    int main() {
    int choice;
    int n;
    int startYear = 1975;
    int endYear;
     int M, N;
    do {
        cout << "MENU:\n";
        cout << "CƠ BẢN:\n";
        cout << "1.Xac dinh so nho hon trong hai so\n";
        cout << "2.Uoc chung lon nhat va boi chung nho nhat\n";
        cout << "3.Ham gia tri n\n";
        cout << "4.Ham tinh X* khong dung de quy\n";
        cout << "5.Tinh ham to hop\n";
        cout << "6.Ham tinh chu vi va dien tinh\n";
        cout << "7.Kiem tra mot so\n";
        cout << "8.Tien\n";
        cout << "9.Dao vi tri\n";
        cout << "NÂNG CAO:\n";
         cout << "10.Bộ đề Tiếng Anh\n";
        cout << "11.Gía trị lớn nhất , sắp xếp dãy\n";
        cout << "12.COVID-19\n";
        cout << "13.Số điện thoại\n";
        cout << "14. mot\n";
        cout << "15.Thể thao\n";
        cout << "16.Ngày,tháng,năm\n";
        cout << "Nhap lua chon (1-16): \n";
        cin >> choice;
        switch (choice) {
            case 1: {
                int a, b, c;
                cout << "Nhập số thứ nhất: ";
                cin >> a;

                cout << "Nhập số thứ hai: ";
                cin >> b;

                int minAB = Sonhonhat2so(a, b);
                cout << "Số nhỏ hơn trong hai số " << a << " và " << b << " là: " << minAB << endl;

                cout << "Nhập số thứ ba: ";
                cin >> c;

                int minABC = Sonhonhat2so(minAB, c);
                cout << "Số nhỏ hơn trong ba số " << a << ", " << b << " và " << c << " là: " << minABC << endl;

                break;
            }
            case 2: {
                int a, b;
                cout << "Nhập hai số nguyên dương a và b: ";
                cin >> a >> b;

                // Kiểm tra nếu người dùng nhập số âm thì yêu cầu nhập lại
                while (a <= 0 || b <= 0) {
                    cout << "Vui lòng chỉ nhập các số nguyên dương. Nhập lại a và b: ";
                    cin >> a >> b;
                }

                int KQ_UCLN = UCLN(a, b);
                int KQ_BCNN = BCNN(a, b);

                cout << "Ước chung lớn nhất (GCD) của " << a << " và " << b << " là: " << KQ_UCLN << endl;
                cout << "Bội chung nhỏ nhất (LCM) của " << a << " và " << b << " là: " << KQ_BCNN << endl;

                break;
            }
            case 3: {
                cout << "Nhập số nguyên dương n (>1): ";
                cin >> n;

                // Kiểm tra nếu người dùng nhập số không hợp lệ thì yêu cầu nhập lại
                while (n <= 1) {
                    cout << "Vui lòng chỉ nhập số nguyên dương (>1). Nhập lại n: ";
                    cin >> n;
                }

                int resultgt = GiaiThua(n);
                cout << n << "! = " << resultgt << endl;

                break;
            }
            case 4: {
                double X;
                int n;

                cout << "Nhập giá trị X: ";
                cin >> X;

                cout << "Nhập số nguyên n: ";
                cin >> n;

                double result = TinhXmuN(X, n);
                cout << X << "^" << n << " = " << result << endl;

                break;
            }
            case 5: {
                int n, k;
                cout << "Nhập giá trị n: ";
                cin >> n;
                cout << "Nhập giá trị k: ";
                cin >> k;

                int ketQua = tinhToHop(n, k);
                cout << "C(" << n << ", " << k << ") = " << ketQua << endl;
                break;
            }
            case 6: {
                int dai, rong;

                cout << "Nhập chiều dài của hình chữ nhật: ";
                cin >> dai;

                cout << "Nhập chiều rộng của hình chữ nhật: ";
                cin >> rong;

                int chuvi = TinhChuVi(dai, rong);
                int dientich = TinhDienTich(dai, rong);

                cout << "Chu vi hình chữ nhật: " << chuvi << endl;
                cout << "Diện tích hình chữ nhật: " << dientich << endl;

                cout << "Hình chữ nhật: " << endl;
                VeHCB(dai, rong);

                break;
            }
            case 7: {
               int N;

                cout << "Nhap so N: ";
                cin >> N;

                InRaSHT(N);

                break;
            }
            case 8: {
                int amount;
                cout << "Nhap so tien can doi: ";
                cin >> amount;

                int num50000, num20000, num10000, num5000, num2000, num1000;
                calculateCurrency(amount, num50000, num20000, num10000, num5000, num2000, num1000);

                cout << "Phuong an tien it nhat la:" << endl;
                cout << "50000: " << num50000 << endl;
                cout << "20000: " << num20000 << endl;
                cout << "10000: " << num10000 << endl;
                cout << "5000: " << num5000 << endl;
                cout << "2000: " << num2000 << endl;
                cout << "1000: " << num1000 << endl;

                break;
            }
            case 9: {
               int n = 12345;
             int reversedN = DaoKiSo(n);

            cout << "Sau khi dao ki so, n = " << reversedN << endl;
                break;
            }
            case 10:
            break;
            case 11:
                    int arr[100];
                    int maxVal;
                    cout << "Nhap so luong phan tu cua day: ";
                    cin >> n;

                    if (n <= 0) {
                        cout << "So luong phan tu khong hop le!" << endl;
                        return 1;
                    }

                    cout << "Nhap cac phan tu cua day: ";
                    for (int i = 0; i < n; i++) {
                        cin >> arr[i];
                    }
                    cout << "Day vua nhap : ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                    maxVal = timGiaTriLonNhat(arr, n);
                    cout << "Gia tri lon nhat cua day la: " << maxVal << endl;
                    int m;
                    cout << "Nhap gia tri m muon chen: ";
                    cin >> m;
                    chenGiaTriTruocGiaTriLonNhat(arr, n , m);
                    cout << "Day sau khi chen gia tri m la: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                    sapXepPhanTuAmVeDauDay(arr,n);
                    cout << "Day sau khi sap xep phan tu am ra dau day : ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;

            break;
            case 12:
       
      int A[100][100];

    // Nhập kích thước ma trận
    cin >> M >> N;

    // Nhập các giá trị của ma trận
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // Tính và in ra kết quả
         int result;
         result = countPotentialInfections(M, N, A);
             cout << result << endl;
            break;
            case 13:
              int T;
                    cin >> T;
                    cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi đọc T
                    while (T--) {
                        string phoneNumber;
                        getline(cin, phoneNumber);

                       //Chuẩn hóa số điện thoại
                        string standardizedPhoneNumber = standardizePhoneNumber(phoneNumber);

                      // Xuất số điện thoại đã chuẩn hóa
                        cout << standardizedPhoneNumber << endl;
                    }
            break;
            case 14:
             int number;
                cout << "Nhap vao mot so co 1 chu so: ";
                cin >> number;
                cout << "Chuoi tuong ung: " << readSingleDigitNumber(number) << endl;

                cout << "Nhap vao mot so co 3 chu so: ";
                cin >> number;
                cout << "Chuoi tuong ung: " << readThreeDigitNumber(number) << endl;

                cout << "Nhap vao mot so nho hon 1,000,000: ";
                cin >> number;
                cout << "Chuoi tuong ung: " << readNumberLessThanOneMillion(number) << endl;
            break;
            case 15:
                cout << "Nhập năm(>= 1975): ";
                cin >> endYear;

                if (endYear < startYear) {
                    cout << "Đầu vào không hợp lệ! Năm cuối phải lớn hơn hoặc bằng năm 1975." << endl;
                    return 1;
                }

                cout << "Các sự kiện thể thao lớn từ " << startYear << " đến " << endYear << " là:" << endl;
                printSportEvents(startYear, endYear);

            break;
            case 16:
                int day, month, year;

                cout << "Nhap vao ngay, thang, nam: ";
                cin >> day >> month >> year;

                if (isValidDate(day, month, year)) {
                    int daysInMonth = getDaysInMonth(month, year);

                    cout << "Thang " << month << " co " << daysInMonth << " ngay." << endl;

                    int nextDay = day, nextMonth = month, nextYear = year;
                    getNextDate(nextDay, nextMonth, nextYear);
                    cout << "Ngay hom sau la: " << nextDay << "/" << nextMonth << "/" << nextYear << endl;

                    int prevDay = day, prevMonth = month, prevYear = year;
                    getPreviousDate(prevDay, prevMonth, prevYear);
                    cout << "Ngay hom truoc la: " << prevDay << "/" << prevMonth << "/" << prevYear << endl;
                }
                else {
                    cout << "Ngay hoac thang khong hop le." << endl;
                }

            break;
            default:
                cout << "Lua chon khong hop le.\n";
        }

    } while (choice != 3);

    return 0;
}
