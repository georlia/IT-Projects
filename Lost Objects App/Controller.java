package laf2828;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.*;
import java.net.URLEncoder;

@WebServlet("/controller")
public class Controller extends HttpServlet {
    
	// Η μέθοδος doPost διαχειρίζεται τα αιτήματα που έρχονται από φόρμες 
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        // Ελληνικα
        request.setCharacterEncoding("UTF-8");
        
        // Λήψη των τιμών από τα πεδία της φόρμας       
        String action = request.getParameter("action"); // εισαγωγη ή διαγραφη
        String description = request.getParameter("description");
        String finder = request.getParameter("finder");
        String location = request.getParameter("location");
        String id = request.getParameter("id"); // Χρησιμοποιείται μόνο στη διαγραφή

        // Καθορισμός της διαδρομής της βάσης δεδομένων SQLite
        String dbPath = getServletContext().getRealPath("/WEB-INF/laf.db");
        String dbURL = "jdbc:sqlite:" + dbPath;

        try {
        	//Φόρτωση του Driver και σύνδεση με τη βάση
            Class.forName("org.sqlite.JDBC");
            Connection conn = DriverManager.getConnection(dbURL);

            if ("insert".equals(action)) {
                // Εντολή SQL Εισαγωγής, με ερωτηματικά (?) για ασφάλεια
                String sql = "INSERT INTO LostAndFound (description, finder, location) VALUES (?, ?, ?)";
                PreparedStatement pstmt = conn.prepareStatement(sql);
                
                // Τοποθέτηση των τιμών στα ερωτηματικά
                pstmt.setString(1, description);
                pstmt.setString(2, finder);
                pstmt.setString(3, location);
               
                // Εκτέλεση της εντολής στη βάση
                pstmt.executeUpdate(); 
                
                // Κλείσιμο σύνδεσης
                pstmt.close();
                conn.close();
                
                // Επιστροφή στην insert.jsp με ένδειξη επιτυχίας (status=ok)
                response.sendRedirect("insert.jsp?status=ok"); 

            } else if ("delete".equals(action)) {
            	// Εντολή SQL για διαγραφή βάσει του ID
                PreparedStatement pstmt = conn.prepareStatement("DELETE FROM LostAndFound WHERE id = ?");
                
                // Μετατροπή του String id σε ακέραιο 
                pstmt.setInt(1, Integer.parseInt(id));
                pstmt.executeUpdate();
                
                // Κλείσιμο σύνδεσης
                pstmt.close();
                conn.close();
                
                // Επιστροφή στη view_all.jsp για να δει ο χρήστης την ανανεωμένη λίστα
                response.sendRedirect("view_all.jsp");
            }

        } catch (Exception e) {
            // Αν συμβεί λάθος το URL επιστροφής με το μήνυμα λάθους και τα δεδομένα
            String errorMsg = URLEncoder.encode(e.getMessage(), "UTF-8");
            
            // Φτιάχνουμε τις παραμέτρους για να ξαναγεμίσουμε τη φόρμα
            String params = "&desc=" + URLEncoder.encode(description, "UTF-8") +
                            "&find=" + URLEncoder.encode(finder, "UTF-8") +               
                            "&loc=" + URLEncoder.encode(location, "UTF-8");
            
            // Ανακατεύθυνση πίσω στην insert.jsp με το σφάλμα και τα παλιά δεδομένα
            response.sendRedirect("insert.jsp?status=error&msg=" + errorMsg + params);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.sendRedirect("index.jsp");
    }
}
