using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Pomelo.EntityFrameworkCore.MySql;

namespace WebAPIExample
{
    public class Startup
    {
        public IConfiguration Configuration { get; }

        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public void ConfigureServices(IServiceCollection services)
        {
            // Configuração da string de conexão
            string connectionString = Configuration.GetConnectionString("MySqlConnection");

            // Adiciona o contexto do banco de dados com a string de conexão
            services.AddDbContext<MyDbContext>(options =>
                options.UseMySql(Configuration.GetConnectionString("MySqlConnection"),
                    new MySqlServerVersion(new Version(8, 0, 36)))); 

            // Adiciona os serviços do controlador da API
            services.AddControllers();
        }

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }

            app.UseRouting();

            app.UseAuthorization();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllers();
            });
        }
    }

    public class MyDbContext : DbContext
    {
        public MyDbContext(DbContextOptions<MyDbContext> options)
            : base(options)
        {
        }

        public DbSet<LoginData> LoginData { get; set; }
    }

    public class LoginData
    {
        public int Id { get; set; }
        public string MachineName { get; set; }
        public DateTime DateTimeLogin { get; set; }
    }
}
