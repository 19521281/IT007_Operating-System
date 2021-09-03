- Với bài tập này mã nguồn tham khảo:

	. Bài toán Bounded Buffer
  
- Lý do:

	. Ban đầu sử dụng biến count để đếm sô lương phần tử được thêm cũng như lấy ra khỏi mảng nhưng sau khi thực thi thì em phát hiện code bị mắc phải lỗi Segmentation fault (core dump) và có sự lệch số.
trong quá trình chuyển đổi từ tiểu trình Push_num sang Pop_num và ngược lại. 

	. Khi áp dụng cách giải bài toán Bounded Buffer và chỉnh lại code thì ý tưởng bài toán như sau:
  
		1. Với hàm Push_num đầu tiên sẽ lấy giá trị của biến full làm giá trị biến đếm số lượng và sau mỗi lần thêm một số vào mảng thì biến full sẽ tăng lên 1 đơn vị.
    
		2. Sau khi chạy sang hàm Pop_num thì lấy giá trị của biến full cuối cùng của hàm Push_num có thể biết được số lượng hiện tại đang có trong mảng và dùng giá trị đó để thực hiện việc giảm số lượng mảng sau khi rút 1 phần tử ra. 
    
-> Việc lấy giá trị của biến full như vậy đảm bảo sự loại trừ tương hỗ, khắc phục được lỗi trên và không xảy ra tình trạng bị lệch số cũng như tính toán không chính xác.


