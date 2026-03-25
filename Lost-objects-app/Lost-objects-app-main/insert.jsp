<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title> Εισαγωγή Αντικειμένων </title>
    
    <style>
        /* Διαμόρφωση σελίδας*/
        body {
            color: #ffffff;
            font-family: sans-serif;           
            text-align: center;
        }
       
        /*Στυλ ονοματος πεδιων Περιγραφη, Ευρων, Τοποθεσια/*/
        label { display: block; margin-top: 10px; text-align: left; }
        
        /*Στυλ τριων πεδιων εισαγωγης δεδομενων*/
        input[type="text"] {
            width: 100%;
            padding: 10px;
            margin-top: 5px;
            border: 1px solid #4a4a3a;
            border-radius: 5px;
            box-sizing: border-box;
            outline: none;
        }
        /*Στυλ Κουμπιου Εισαγωγής*/
        input[type="submit"] {
            margin-top: 25px;
            padding: 12px;
            background-color: #3e6b27;
            color: white;
            border-radius: 5px;
            cursor: pointer;
            width: 100%;
            font-size: 1.1em;
        }
        
        .error-msg { color: #ff3333; margin-bottom: 15px;} /*Στυλ error μηνυματος εισαγωγης*/
        .success-msg { color: #00ff00; margin-bottom: 15px; } /*Στυλ σωστου μηνυματος εισαγωγης*/
        a { color: #4a90e2; text-decoration: none; display: block; margin-top: 20px; }/*Στυλ συνδεσμου που παει στην αρχικη οθονη*/
    </style>
</head>

<body>
    <h1> Εισαγωγή Αντικειμένων </h1>
    <%
       /* Ο τρόπος που μεταφέρουμε πληροφορίες από το Servlet πίσω στην JSP σελίδα μέσω των παραμέτρων του URL*/
       String status = request.getParameter("status");
       String errorMsg = request.getParameter("msg");
       
       String d = "";  //περιγραφη
       String f = "";  //ευρων
       String l = "";  //τοποθεσια

        //Έλεγχος αν ο controller μας έστειλε πίσω τις τιμές που πληκτρολογήσαμε
       if (request.getParameter("desc") != null) {
           d = request.getParameter("desc");
       }
       if (request.getParameter("find") != null) {
           f = request.getParameter("find");
       }
       if (request.getParameter("loc") != null) {
           l = request.getParameter("loc");
       }
            
       if (status != null) {
    	   // Αν το status είναι ok
           if (status.equals("ok")) {
   %>
               <h3 class="success-msg">Η Εισαγωγή ολοκληρώθηκε </h3>
   <%      
           // Αν το status είναι error
           } else if (status.equals("error")) { 
   %>
               <p class="error-msg">Πρόβλημα με την εισαγωγή: <%= errorMsg %> </p>
   <% 
           }
       }
   %>
 
    <p> Παρακαλώ δώστε τα ακόλουθα στοιχεία: </p>
    
    <form action="controller" method="POST">
        <input type="hidden" name="action" value="insert">

        <label>Περιγραφή:</label>
        <input type="text" name="description" value="<%= d %>">

        <label>Ευρών:</label>
        <input type="text" name="finder" value="<%= f %>">

        <label>Τοποθεσία:</label>
        <input type="text" name="location" value="<%= l %>">

        <input type="submit" value="Εισαγωγή">
    </form>
   
    <a href="index.jsp">Επιστροφή στην αρχική σελίδα </a>

    <p> Δημιουργήθηκε από την Γεωρλια </p>
</body>
</html>
