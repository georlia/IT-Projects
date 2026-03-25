package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.*;
import java.util.*;


@WebServlet("/show-items2")
public class ShowItems2 extends HttpServlet {
  @Override
  public void doPost (HttpServletRequest request,
                      HttpServletResponse response)
  throws ServletException, IOException {

/* Η ακόλουθη είναι μια απλή αλλαγή που μας βοηθά να
 πετύχουμε το στόχο μας. Βασικά στην αρχή του κώδικα
 μπορούμε να ανιχνεύσουμε αν πατήθηκε το κουμπί Clear στο
 οποίο έχουμε δώσει (πιο κάτω) το όνομα clear.
 Αν πατήθηκε ακυρώνουμε το session όποτε η κλήση getSession
 που θα ακολουθήσει θα επιστρέψει ένα νέο αντικείμενο
session που θα είναι κενό.
 */
	  
if (request.getParameter("clear") != null) {
    request.getSession().invalidate();
}

HttpSession session = request.getSession();

synchronized(session) {
  @SuppressWarnings("unchecked")
  List<String> previousItems =
  (List<String>)session.getAttribute("previousItems");
  if (previousItems == null) {
      previousItems = new ArrayList<String>();
  }
  String newItem = request.getParameter("newItem");
  if ((newItem != null) &&
     (!newItem.trim().equals(""))) {
     previousItems.add(newItem);
  }
  session.setAttribute("previousItems", previousItems);
  response.setContentType("text/html");
  PrintWriter out = response.getWriter();
  String title = "Items Purchased";
  String docType =
  "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 " +
  "Transitional//EN\">\n";
  out.println(docType +
              "<HTML>\n" +
              "<HEAD><TITLE>" + title + "</TITLE></HEAD>\n" +
              "<BODY BGCOLOR=\"#FDF5E6\">\n" +
              "<H1>" + title + "</H1>");
  if (previousItems.size() == 0) {
      out.println("<I>No items</I>");
  } else {
    out.println("<UL>");
  for(String item: previousItems) {
      out.println(" <LI>" + item);
  }
   out.println("</UL>");
  }
  /*
  * Η ακόλουθη εντολή θα δημιουργήσει το κουμπί Clear με
  * όνομα clear μεσα σε μια φόρμα. Αποφεύγοντας να ορίσουμε
  * ιδιότητα action για την φόρμα αναγκάζουμε την φόρμα να
  * στείλει την αίτηση στο ιδιο URL με το εγγραφο που την
  * περιέχει δηλαδή στο URL του servlet.
  */
  out.println("<form method=\"post\"> \n" +
              "<input type=\"submit\" name=\"clear\" value=\"Clear\" > \n" +
              "</form> \n");
  /*
  * Η ακόλουθη εντολή δημιουργεί τον υπερσύνδεσμο "Back to Orders"
  * προς το html εγγραφο.
  */
  out.println("<a href=\"order-form2.html\" >Back to Orders</a>");
  out.println("</BODY></HTML>");
  }
 }
}
