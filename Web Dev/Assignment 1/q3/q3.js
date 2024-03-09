document.getElementById("validationForm").addEventListener("submit", function(event) {
    event.preventDefault();
   
    
    let formData = {
        firstName: document.getElementById('firstName').value,
        lastName: document.getElementById('lastName').value,
        phoneNumber: document.getElementById('phoneNumber').value,
        email: document.getElementById('email').value,
        street: document.getElementById('street').value,
        city: document.getElementById('city').value,
        state: document.getElementById('state').value,
        zipCode: document.getElementById('zipCode').value,
        resume: document.getElementById('resume').value,
        coverLetter: document.getElementById('coverLetter').value,
        educationLevel: document.getElementById('educationLevel').value,
        schoolName: document.getElementById('schoolName').value,
        major: document.getElementById('major').value,
        graduationYear: document.getElementById('graduationYear').value,
        jobTitle: document.getElementById('jobTitle').value,
        companyName: document.getElementById('companyName').value,
        employmentDates: document.getElementById('employmentDates').value,
        jobResponsibilities: document.getElementById('jobResponsibilities').value,
        relevantSkills: document.getElementById('relevantSkills').value,
        certifications: document.getElementById('certifications').value,
        startDate: document.getElementById('startDate').value,
        workSchedule: document.getElementById('workSchedule').value,      
        referenceName: document.getElementById('referenceName').value,
        referenceContact: document.getElementById('referenceContact').value,
        relationship: document.getElementById('relationship').value,
        whyWorkHere: document.getElementById('whyWorkHere').value,
        termsAndConditions: document.getElementById('termsAndConditions').checked,
        privacyPolicy: document.getElementById('privacyPolicy').checked,      
    };

    let submittedForms = JSON.parse(localStorage.getItem("submittedForms")) || [];
    submittedForms.push(formData);
    localStorage.setItem("submittedForms", JSON.stringify(submittedForms));
    alert("Form submitted successfully!");
    document.getElementById("validationForm").reset();
  });
  
  document.getElementById("viewSubmitted").addEventListener("click", function() {
    let submittedForms = JSON.parse(localStorage.getItem("submittedForms")) || [];
    let tableHtml = "<table><tr><th>Name</th><th>Email</th><th>Phone Number</th><th>Education Level</th><th>School Name</th><th>Graduation Year</th><th>Previous Job Title</th><th>Company Name</th><th>Employment Dates</th><th>Skills</th><th>Start Date</th></tr>";
    
    submittedForms.forEach(function(form) {
      tableHtml += "<tr>";
      tableHtml += "<td>" + form.firstName + form.lastName + "</td>";
      tableHtml += "<td>" + form.email + "</td>";
      tableHtml += "<td>" + form.phoneNumber + "</td>";
      tableHtml += "<td>" + form.educationLevel + "</td>";
      tableHtml += "<td>" + form.schoolName + "</td>";
      tableHtml += "<td>" + form.graduationYear + "</td>";
      tableHtml += "<td>" + form.jobTitle + "</td>";
      tableHtml += "<td>" + form.companyName + "</td>";
      tableHtml += "<td>" + form.employmentDates + "</td>";
      tableHtml += "<td>" + form.relevantSkills + "</td>";
      tableHtml += "<td>" + form.startDate + "</td>";
      tableHtml += "</tr>";
    });
    
    tableHtml += "</table>";
    document.getElementById("submittedForms").innerHTML = tableHtml;
});
