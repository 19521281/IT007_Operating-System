Các trang web em sử dụng để tham khảo:
- [Code SRT](https://www.edureka.co/blog/sjf-scheduling-in-c/)
- [Đọc và ghi File](https://www.cs.utah.edu/~germain/PPS/Topics/C_Language/file_IO.html)

Trong đoạn code trên, em đã có 1 số thay dổi để phù hợp với yêu cầu như:
	- Viết hàm đọc dữ liệu chỉ có số từ file input.txt gán vào các biến tương ứng thay vì nhập từ bàn phím
	- Tạo 1 biến flag để đánh dấu tiến trình nào đã được thực thi rồi
	- Tạo 1 biến come để lưu trữ thời gian mà tiến trình được gọi vào thực thi sau đó dùng arrival - come để ra được response
	- Viết hàm ghi các dữ liệu từ file input.txt cũng như dữ liệu đã tính toán vào file output.txt, nếu file output.txt chưa được khởi tạo thì code sẽ tự động tạo và ghi dữ liệu vào

Các hàm xử lý File được dùng:
	. fopen("filepath", "mode"): mở tệp mới hoặc file đang tồn tại
	. fprintf("filepath", "kiểu dự liệu", biến): ghi dữ liệu vào file
	. fscanf("filepath", "kiểu dự liệu", &biến): đọc dữ liệu từ file
	. fclose(): đóng file
	. Mode "r": đọc file văn bản
	. Mode "w+": ghi và cập nhật lại dữ liệu file văn bản
	. File *file: tạo con trỏ

Đoạn code trên em giữ lại cách tìm waiting time và turnaround time nhưng chỉ thay đổi tên biến 
