package mypackage;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.*;

/** Simple servlet for testing. Generates HTML instead of plain
 *  text as with the HelloWorld servlet.
 */

@WebServlet("/tryme")
public class MyServlet extends HttpServlet {
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
       "<head><title>My Servlet</title></head>\n" +
       "<body bgcolor=\"#fdf5e6\">\n" +
       "<h1>Αυτή είναι η πρώτη μου Μικρουπηρεσία(Servlet)</h1>\n" +
       "<p>Georlia</p>\n" +
       "</body></html>");
  }
}
//localhost/myproject/tryme
