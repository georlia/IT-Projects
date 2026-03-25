package mypackage;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*; 

@WebServlet("/mylist")
public class ListExample extends HttpServlet {
  @Override
  public void doGet(HttpServletRequest request,
			        HttpServletResponse response)
	  throws ServletException, IOException {
	response.setContentType("text/html");
	response.setCharacterEncoding("UTF-8");
	PrintWriter out = response.getWriter();
	out.println
	  ("<!DOCTYPE html>\n" +
	   "<html>\n" +
	   "<head><title>A List Example</title></head>\n" +
	   "<body bgcolor=\"#fdf5e6\">\n" +
	   "<h1>A List Example</h1>\n" +
	   "<ul>\n"
	  );
	  for (int i = 0; i<=10; i++){
	      out.println("<li>"+ Math.random() + "</li>");
	  }
	  out.println("</ul></body></html>");
   }
}
//http://localhost/myproject/mylist
