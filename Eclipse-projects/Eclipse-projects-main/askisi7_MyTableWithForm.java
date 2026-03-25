package mypackage;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*; 

@WebServlet("/mytableform")
public class MyTableWithForm extends HttpServlet {
  @Override
  public void doGet(HttpServletRequest request,
                    HttpServletResponse response)
      throws ServletException, IOException {

    response.setContentType("text/html");
    response.setCharacterEncoding("UTF-8");
    PrintWriter out = response.getWriter();

    String r = request.getParameter("rowCount");
    String c = request.getParameter("columnCount");

    int rows = 0, cols = 0;

    try {
      if (r != null) rows = Integer.parseInt(r);
      if (c != null) cols = Integer.parseInt(c);
    } catch (Exception e) {}

    out.println("<!DOCTYPE html>\n" +
       "<html>\n" +
       "<head><title>A Table Generating Example</title></head>\n" +
       "<body bgcolor=\"#fdf5e6\">\n" +
       "<h1>A Table Generating Example</h1>\n" +

       "<form>" +
       "Row Count: <input type='text' name='rowCount' value=''><br>" + 
       "Column Count: <input type='text' name='columnCount' value=''><br>" +
       "<input type='submit' name='makeTable' value='Make Table'><br>" +
       "</form><br>"
    );

    if (rows > 0 && cols > 0) {

      out.println("<table border='1'>");

      // Header row
      out.println("<tr>");
      for (int j = 1; j <= cols; j++) {
        out.println("<th>Header " + j + "</th>");
      }
      out.println("</tr>");

      // Table rows
      for (int i = 1; i <= rows; i++) {
        out.println("<tr>");
        for (int j = 1; j <= cols; j++) {
          out.println("<td>row " + i + ", col " + j + "</td>");
        }
        out.println("</tr>");
      }

      out.println("</table>");
    }
    out.println("</body></html>");
  }
}

//localhost/myproject/mytableform
