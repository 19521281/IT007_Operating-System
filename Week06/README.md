Bài code được tham khảo từ [GitHub](https://github.com/MichaelJFodor/Page_Replacement_Algorithms)
Với bài code này sẽ dùng:

	. malloc và calloc để cấp phát bộ nhớ động cho các biến Seq(chứa chuỗi đầu vào), fault(chứa dấu * kkhi phát hiện lỗi) và table(quá trình thêm trang)
  
	. sử dụng switch case để lựa chọn thuật toán muốn thực hiện 
  
	. trong từng case sau khi đã thực hiện với khung trang ban đầu, tiếp tục xét trường hợp tăng thêm 1 khung để kiểm tra nghịch lý belady có xảy ra hay không
  
	. tăng thêm khung trang nên bắt buộc phải tạo một biến table mới và tùy từng case sẽ được đặt tên tương ứng với thuật toán đó table_[algorithm]
  
	. thuật toán FIFO, nếu như đã điền hết khung trang và xuất hiện 1 trang mới chưa có trong khung trang sẽ dùng start để đưa ra vị trí mà trang đó sẽ được nạp vào khung
  
		. tạo 1 hàm kiểm tra khung trang để xem các khung trang còn trống hay đã được điền đầy và các trang đã có trong khung trang rồi hay chưa
    
	. thuật toán OPT, tạo 1 biến predict gồm các ô nhớ tương ứng với số lượng khung trang
  
		. ô đầu tiên sẽ lưu vị trí xuất hiện kế tiếp của số đầu tiên
    
		. sau khi thực hiện hàm kiểm tra khung trang để kiểm tra lỗi hoặc thêm trang đều phải thực hiện một bước tìm kiếm lần xuất hiện tiếp theo của trang đó
    
		. nếu như trong trường hợp khung trang đầy nhưng xuất hiện trang mới cần phải so sánh các giá trị trong ô nhớ của predict để lựa chọn vị trí nào có giá trí lớn nhất thì sẽ thêm trang vào thay thế giá trị ở vị trí khung đó
    
	. thuật toán LRU, tương tự như OPT cũng tạo 1 biến latest
  
		. ô đầu tiên sẽ lưu số 0 cho trang đầu tiên nghĩa là trang đầu tiên được truy cập trước
    
		. sau khi thực hiện hàm kiểm tra khung trang để kiểm tra lỗi hoặc thêm trang đều phải thực hiện một bước lưu vị trí của trang đó ở trong biến Seq vào ô nhớ tiếp theo
    
	. kiểm tra khung trang xong sẽ trả về 2 trường hợp:
  
		. khung trang còn trống và trang mới chưa có trong khung sẽ được lưu vào vị trí tương ứng của nó và thêm vào fault một dấu * để đánh dấu lỗi
    
		. khung trang còn trống nhưng trang đã có trong khung rồi thì thêm vào fault một khoảng trắng với ý nghĩa không có lỗi
    
		. nếu khung trang đã đầy thì tùy vào từng thuật toán để thực hiện việc thay thế trang
