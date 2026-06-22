//Function typeWriter - Write H2
function typeWriter(elemento) {
  const textoArray = elemento.innerHTML.split(''); // Take the text and divide it into letters.
  elemento.innerHTML = ''; // Clear original content

  textoArray.forEach((letra, i) => {
    setTimeout(() => {
      elemento.innerHTML += letra; // Add each letter
    }, 75 * i); // 75ms delay per letter
  });
}

// Profile Data - can be expanded or fetched from a server in a real application
const profiles = [{
        fullName: "Anderson Moreton",
        job: "Front-End Developer",
        location: "Chaves, Portugal",
        image: "./img/profileMan.png",
        email: "anderson.moreton@email.com",
        phone: "+351 911 916 416",
        skills: ["JavaScript", "HTML", "CSS", "Bootstrap", "Angular"],
        experience: [
            "2+ years as a Software Engineer",
            "Web application development",
            "API integration and performance optimization"
        ]
    },
    {
        fullName: "Leonardo La Roque",
        job: "UI/UX Designer",
        location: "Porto, Portugal",
        image: "./img/profileWoman.jpeg",
        email: "leonardo.la.roque@email.com",
        phone: "+351 911 916 416",
        skills: ["C Programming Language", "Data Structures and Algorithms", "Linux/Unix Systems"],
        experience: [
            "2+ years as a C Programming Language Developer",
            "Development and maintenance of high-performance backend systems using C",
            "Integration with databases, APIs, and low-level system components"
        ]
    }
];

const modal = new bootstrap.Modal(document.getElementById('profileModal'));

// Add event listeners to profile cards - opens modal on click
document.querySelectorAll('.profile-card').forEach(card => {
    card.addEventListener('click', () => {
        openModal(card.dataset.profile);
    });
});

// Function to open modal and populate with profile data - called when a profile card is clicked
function openModal(index) {
    const p = profiles[index];
    // Populate modal fields

    document.getElementById('modalFullName').innerText = p.fullName;
    document.getElementById('modalJob').innerText = p.job;
    document.getElementById('modalLocation').innerText = p.location;
    document.getElementById('modalImage').src = p.image;

    document.getElementById('modalSkills').innerHTML =
        p.skills.map(skill => `<span class="badge bg-primary">${skill}</span>`).join(''); // Badges

    document.getElementById('modalExperience').innerHTML =
        p.experience.map(exp => `<li>${exp}</li>`).join(''); // List items

    const email = document.getElementById('modalEmail');
    email.innerText = p.email;
    email.href = `mailto:${p.email}`; // Mailto link

    const phone = document.getElementById('modalPhone'); // Updated ID to 'modalPhone'
    phone.innerText = p.phone;
    phone.href = `tel:${p.phone.replace(/\s/g, '')}`; // Remove spaces for tel link

    // Ensure contact info is hidden initially
    document.getElementById('contactInfo').classList.remove('show');

    modal.show();
}